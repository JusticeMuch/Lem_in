/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:19:41 by jronald           #+#    #+#             */
/*   Updated: 2018/06/04 14:10:40 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	j = ft_strlen(src);
	i = 0;
	while (i < len)
	{
		if (i > j)
			dest[i] = '\0';
		else
			dest[i] = source[i];
		i++;
	}
	if (dest == NULL)
		return (NULL);
	return (dst);
}
