/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:58:07 by jkollner          #+#    #+#             */
/*   Updated: 2023/03/17 10:59:45 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include "printf/ft_printf.h"

int	input_handler(int args, char *argv[]);
int	translate_pid(const char *str);
int	send_message(int pid, char *message);

#endif
