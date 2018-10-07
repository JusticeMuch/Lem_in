/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 00:41:46 by jronald           #+#    #+#             */
/*   Updated: 2018/06/04 13:58:24 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;

	i = 0;
	source = (unsigned char*)src;
	dest = (unsigned char*)dst;
	while (i < n)
	{
		dest[i] = source[i];
		if ((unsigned char)source[i] == (unsigned char)c)
			return (unsigned char*)(dest + ++i);
		i++;
	}
	return (NULL);
}
