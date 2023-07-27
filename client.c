/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:40:38 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/18 15:30:08 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdlib.h>

void	sig_handler_c(int signo)
{
	if (signo == SIGUSR2)
		ft_printf("Server got string \n");
}

int	main(int args, char *argv[])
{
	pid_t	pid;

	pid = input_handler(args, argv);
	if (pid == -1)
		return (-1);
	if (signal(SIGUSR1, sig_handler_c) == SIG_ERR
		|| signal(SIGUSR2, sig_handler_c) == SIG_ERR)
		return (ft_printf("\ncan't attach signals\n"), -1);
	send_message(pid, ft_itoa(ft_strlen(argv[2])));
	send_message(pid, "\0");
	send_message(pid, argv[2]);
	send_message(pid, "\0");
	system("leaks client");
	return (ft_printf("Exiting...\n"), 1);
}
