/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:42:58 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/13 11:37:26 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*c_dest;
	const char	*c_src;

	if (dst == NULL && src == NULL)
		return (dst);
	c_dest = dst;
	c_src = src;
	if (src < dst)
	{
		c_src = src + (len - 1);
		c_dest = dst + (len - 1);
		while (len--)
			*c_dest-- = *c_src--;
	}
	else
	{
		while (len--)
			*c_dest++ = *c_src++;
	}
	return (dst);
}
