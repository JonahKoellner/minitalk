/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:44:55 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/13 11:35:58 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
Handles the in main given input to check for amount and type arguments.
It also checks if the given process exists.
*/
int	input_handler(int args, char *argv[])
{
	int	pid;

	if (args != 3)
		return (ft_printf("Not the right amount of Parameters. Exiting!\n"), -1);
	pid = translate_pid(argv[1]);
	if (pid == -1)
		return (ft_printf("Given pid is not a valid pid"), -1);
	if (kill(ft_atoi(argv[1]), 0) == -1)
		return (ft_printf("Process does not exist .... Exiting!\n"), -1);
	return (pid);
}

// atoi with check if only real number
int	translate_pid(const char *str)
{
	int	ret_val;

	ret_val = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret_val *= 10;
		ret_val += *str - '0';
		str++;
	}
	if (*str != 0x00)
		return (-1);
	return (ret_val);
}

void	send_byte_sig(int pid, char character)
{
	int	bit;
	int	j;

	// ft_printf("byte c: %c (%d)\n", character, character);

	j = 7;
	while (j >= 0)
	{
		bit = character >> j & 1;
		if (bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		j--;
		usleep(100);
	}
}

/*
Sends message in binary form to pid by using system sinals
*/
int	send_message(int pid, char *message)
{
	int	counter;

	counter = 0;
	// ft_printf("sending: %s\n", message);

	if (*message == '\0')
		send_byte_sig(pid, '\0');

	while (message[counter])
		send_byte_sig(pid, message[counter++]);
	return (0);
}
