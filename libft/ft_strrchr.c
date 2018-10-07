/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:54:30 by jronald           #+#    #+#             */
/*   Updated: 2018/06/04 15:33:11 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*y;
	char	*h;

	i = 0;
	y = (char*)s;
	h = NULL;
	while (y[i] != '\0')
	{
		if (y[i] == c)
			h = (y + i);
		i++;
	}
	if (c == '\0')
		return (y + i);
	else
		return (char*)(h);
}
