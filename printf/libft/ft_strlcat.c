/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:18:47 by jkollner          #+#    #+#             */
/*   Updated: 2023/04/13 11:37:42 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	dst_len;
	int	src_len;
	int	counter;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (src_len == 0 && (int)dstsize < dst_len)
		return (dstsize);
	counter = 0;
	while (dst_len + counter < (int)dstsize - 1 && src[counter])
	{
		dst[dst_len + counter] = src[counter];
		counter++;
	}
	while (dst_len + counter < (int)dstsize)
		dst[dst_len + counter++] = '\0';
	if (dst_len > (int)dstsize)
		return (src_len + dstsize);
	return (dst_len + src_len);
}
