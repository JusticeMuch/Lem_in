/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:26:21 by jronald           #+#    #+#             */
/*   Updated: 2018/06/01 07:33:12 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*j;

	i = 0;
	j = (char*)s;
	while (j[i] != '\0')
	{
		if (j[i] == c)
			return (j + i);
		i++;
	}
	if (c == 0)
	{
		return (j + i);
	}
	else
	{
		return (NULL);
	}
}
