/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:50:08 by jronald           #+#    #+#             */
/*   Updated: 2018/06/05 17:59:42 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
		c == '\r');
}

char		*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*res;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s) - 1;
	while ((check_space(s[i])) && s[i])
		i++;
	while ((check_space(s[j])) && j)
		j--;
	if ((i == 0) && (j == (ft_strlen(s) - 1)))
		return (ft_strdup(s));
	if (j > i)
		k = j - i;
	res = ft_strnew(k + 2);
	if (res == NULL)
		return (NULL);
	if (j == 0 && !(s[i]))
		return (res);
	ft_memcpy(res, (s + i), (k + 1));
	return (res);
}
