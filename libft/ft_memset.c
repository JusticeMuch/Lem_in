/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 22:52:06 by jronald           #+#    #+#             */
/*   Updated: 2018/06/01 07:21:31 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*res;
	size_t		i;

	i = 0;
	res = b;
	while (i < len)
	{
		*(res + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
