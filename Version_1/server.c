/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:40:41 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/19 14:17:38 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void	sig_handler_s(int signo, siginfo_t *client_info, void *idk)
{
	static int				times;
	static int				c_pid;
	static unsigned char	character;

	(void) idk;
	if (client_info->si_pid != 0)
		c_pid = client_info->si_pid;
	if (!times)
		times = 0;
	if (!character)
		character = 0;
	character <<= 1;
	character += signo == SIGUSR2;
	if (++times == 8)
	{
		write(STDOUT_FILENO, &character, 1);
		if (character == '\0')
		{
			ft_printf("\n");
			kill(c_pid, SIGUSR2);
		}
			times = 0;
		character = 0;
	}
	kill(c_pid, SIGUSR1);
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
