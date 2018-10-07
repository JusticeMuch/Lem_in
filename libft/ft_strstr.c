/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:17:57 by jronald           #+#    #+#             */
/*   Updated: 2018/06/05 16:20:25 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	int		i;
	int		j;
	char	*s;

	s = (char*)hay;
	i = 0;
	j = 0;
	if (*needle == '\0')
		return (s);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return (char*)(s + i);
		i++;
	}
	return (NULL);
}
