/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 00:27:28 by jronald           #+#    #+#             */
/*   Updated: 2018/06/04 13:58:54 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*res;
	char	*source;

	i = 0;
	source = (char*)src;
	res = dst;
	while (i < n)
	{
		res[i] = source[i];
		i++;
	}
	return (unsigned char*)(dst);
}
