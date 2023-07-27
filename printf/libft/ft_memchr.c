/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:38:20 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/13 11:37:20 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	int			counter;

	str = s;
	counter = 0;
	while (counter < (int)n)
	{
		if (str[counter] == (char)c)
			return ((void *)&str[counter]);
		counter++;
	}
	return ((void *)0);
}

