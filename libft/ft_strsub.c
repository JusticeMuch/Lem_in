/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:44:06 by jronald           #+#    #+#             */
/*   Updated: 2018/06/04 14:26:45 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	i = 0;
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[start] = '\0';
	return (res);
}
