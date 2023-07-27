/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:40:41 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/19 14:41:20 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int g_state = 0;

void	handle_byte_message(char byte_char, siginfo_t *client_info)
{
	static char	*buffer;
	static char	*length;
	static int	index;

	if (!length)
		length = ft_calloc(11, sizeof(char));
	if (!index)
		index = 0;
	if (g_state == 0)
	{
		if (!byte_char)
		{
			buffer = ft_calloc(ft_atoi(length) + 1, sizeof(char));
			free(length);
			length = NULL;
			index = 0;
			g_state = 1;
		}
		else
			length[index++] = byte_char;
	}
	else if (g_state == 1)
	{
		if (!byte_char)
		{
			ft_printf("%s\n", buffer);
			kill(client_info->si_pid, SIGUSR2);
			free(buffer);
			buffer = NULL;
			index = 0;
			g_state = 0;
		}
		else
			buffer[index++] = byte_char;
	}
}

void	sig_handler_s(int signo, siginfo_t *client_info, void *idk)
{
	static int				times;
	static unsigned char	character;

	(void) idk;
	if (!times)
		times = 0;
	if (!character)
		character = 0;
	character <<= 1;
	character += signo == SIGUSR2;
	if (++times == 8)
	{
		handle_byte_message(character, client_info);
			times = 0;
		character = 0;
	}
	kill(client_info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: %d\n", getpid());
	act.sa_sigaction = &sig_handler_s;
	act.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
