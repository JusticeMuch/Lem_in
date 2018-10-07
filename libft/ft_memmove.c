/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 02:09:56 by jronald           #+#    #+#             */
/*   Updated: 2018/06/04 13:59:55 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (char*)dst;
	source = (char*)src;
	i = 0;
	if (dest > source)
	{
		while (len--)
		{
			*(dest + len) = *(source + len);
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
