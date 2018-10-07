/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:35:20 by jronald           #+#    #+#             */
/*   Updated: 2018/06/06 16:50:55 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (d_len >= (dstsize - 1) || dstsize == 0)
	{
		return (dstsize + s_len);
	}
	else if (d_len < (dstsize - 1))
	{
		while ((i + d_len) < (dstsize - 1) && *src)
		{
			dst[i + d_len] = *src;
			i++;
			src++;
		}
		dst[i + d_len] = '\0';
		return (s_len + d_len);
	}
	return (0);
}
