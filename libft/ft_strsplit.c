/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 07:19:27 by jronald           #+#    #+#             */
/*   Updated: 2018/09/12 12:41:29 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_arr(char *s1, const char *s2, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s2[i] != c && s2[i])
	{
		i++;
	}
	s1 = (char*)malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		s1[j] = s2[j];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**res;
	size_t	j;
	size_t	k;
	size_t	l;

	if (s == NULL)
		return (NULL);
	j = 0;
	k = 0;
	l = ft_del_count((char*)s, c) + 1;
	res = (char**)malloc(sizeof(char*) * l);
	if (res == NULL)
		return (NULL);
	while (s[k])
	{
		if (s[k] != c && (s[k - 1] == c || k == 0) && s[k])
		{
			res[j] = fill_arr(res[j], (s + k), c);
			j++;
		}
		k++;
	}
	res[j] = NULL;
	return (res);
}
