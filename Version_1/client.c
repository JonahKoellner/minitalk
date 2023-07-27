/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:40:38 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/19 14:49:33 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void	sig_handler_c(int signo)
{
	if (signo == SIGUSR2)
		ft_printf("Server responded that he got the string\n");
}

void	send_bit_sig(int pid, char character)
{
	int	bit;
	int	j;

	j = 7;
	while (j >= 0)
	{
		bit = character >> j & 1;
		if (bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		j--;
		usleep(600);
	}
}

int	main(int args, char *argv[])
{
	int		i;
	pid_t	pid;
	char	character;

	if (args != 3)
		return (ft_printf("Wrong amount of Parameters... Exiting!\n"), -1);
	if (kill(ft_atoi(argv[1]), 0) == -1)
		return (ft_printf("Process does not exist .... Exiting!\n"), -1);
	pid = ft_atoi(argv[args - 2]);
	if (signal(SIGUSR1, sig_handler_c) == SIG_ERR)
		return (ft_printf("\ncan't catch SIGUSR1\n"), -1);
	if (signal(SIGUSR2, sig_handler_c) == SIG_ERR)
		return (ft_printf("\ncan't catch SIGUSR2\n"), -1);
	i = 0;
	while (argv[2][i])
	{
		character = argv[2][i];
		send_bit_sig(pid, character);
		i++;
	}
	send_bit_sig(pid, '\0');
	return (ft_printf("String send... Successfully Exiting :)\n"), 1);
}
