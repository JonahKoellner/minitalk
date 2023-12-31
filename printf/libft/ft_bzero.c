/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:29:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/18 14:31:09 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		counter;
	char	*void_cast;

	void_cast = s;
	counter = 0;
	while (counter < (int)n)
	{
		void_cast[counter] = 0;
		counter++;
	}
}
