/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:45:41 by jronald           #+#    #+#             */
/*   Updated: 2018/06/06 17:05:05 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_del_count(char *s, char c)
{
	size_t	i;

	i = 1;
	if (!s)
		return (i);
	while (*s)
	{
		if (*s != c && *(s + 1) == c && *(s + 1))
			i++;
		s++;
	}
	return (i);
}