/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:55:38 by jronald           #+#    #+#             */
/*   Updated: 2018/06/05 16:22:21 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (hay[i] != '\0' && i < n)
	{
		j = 0;
		while (hay[i + j] == need[j] && need[j] && (i + j) < n)
		{
			j++;
		}
		if (need[j] == '\0')
			return (char*)(hay + i);
		i++;
	}
	if (need == NULL)
	{
		return ((char*)hay);
	}
	else
	{
		return (NULL);
	}
}
