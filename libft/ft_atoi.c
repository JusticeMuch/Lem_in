/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 22:35:21 by jronald           #+#    #+#             */
/*   Updated: 2018/08/20 07:37:13 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space(char c)
{
	return (c == '\n' || c == '\t' || c == ' ' || c == '\f' || c == '\r' ||
			c == '\v');
}

int			ft_atoi(const char *str)
{
	int		res;
	int		neg;

	res = 0;
	neg = 1;
	while (*str && (check_space(*str)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str != '\0' && (*str >= 48 && *str <= 57))
	{
		if (*str >= 48 && *str <= 57)
		{
			res = (res * 10) + (int)(*str - 48);
			str++;
		}
		else
			return (0);
	}
	return (res * neg);
}
