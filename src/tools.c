/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:00:25 by jronald           #+#    #+#             */
/*   Updated: 2018/09/20 16:53:17 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leming.h"

void	free_arr(char ***arr)
{
	char	**temp;
	int		i;

	i = 0;
	temp = *arr;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

int		get_index(t_stuff *u, char *temp)
{
	int i;
	int ret;

	ret = -1;
	i = -1;
	while (++i <= u->room_num)
		ret = (ft_strcmp(temp, u->rooms[i]) == 0) ? i : ret;
	return (ret);
}

int		check_pre_room(t_stuff *u, int ind)
{
	t_path *temp;

	temp = u->path;
	while (temp->next)
	{
		if (temp->current_room == ind)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		check_for_incomplete(t_stuff *u)
{
	int		**temp;
	int		i;

	i = 0;
	temp = u->solve;
	while (i <= u->room_num)
	{
		if (temp[0][i] == 1)
			return (0);
		i++;
	}
	return (1);
}

void	set_zero(int *val1, int *val2)
{
	*val1 = 0;
	*val2 = 0;
}
