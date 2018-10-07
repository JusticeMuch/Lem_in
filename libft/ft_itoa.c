/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:04:18 by jronald           #+#    #+#             */
/*   Updated: 2018/06/06 12:15:50 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_len(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i - 1);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*res;

	i = in_len(n);
	res = ft_strnew(i + 1);
	if (!res)
		return (NULL);
	if (n == -2147483648)
		ft_strcpy(res, "-2147483648");
	if (n == 0)
		ft_strcpy(res, "0");
	if (n < 0 && n != -2147483648)
		res[0] = '-';
	while (n != 0 && n != -2147483648)
	{
		if (n > 0)
			res[i] = (n % 10 + '0');
		else if (n < 0)
			res[i] = (n % 10 * -1 + '0');
		n /= 10;
		i--;
	}
	return (res);
}
