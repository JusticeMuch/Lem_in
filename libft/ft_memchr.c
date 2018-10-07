/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:30:10 by jronald           #+#    #+#             */
/*   Updated: 2018/06/01 07:17:22 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char*)s;
	while (i < n)
	{
		if ((unsigned char)res[i] == (unsigned char)c)
		{
			return (unsigned char*)(s + i);
		}
		i++;
	}
	return (NULL);
}
