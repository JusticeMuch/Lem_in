/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:32:01 by jronald           #+#    #+#             */
/*   Updated: 2018/09/20 17:00:20 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leming.h"

int			fill_algo_array(t_stuff *u)
{
	int		index;

	index = -1;
	u->solve = (int**)malloc(sizeof(int*) * (u->room_num + 1));
	while (++index <= u->room_num)
		u->solve[index] = (int*)malloc(sizeof(int) * (u->room_num + 1));
	index = -1;
	while (++index < u->room_c)
	{
		u->solve[u->rc[index][0]][u->rc[index][1]] = 1;
		u->solve[u->rc[index][1]][u->rc[index][0]] = 1;
	}
	return (0);
}

t_path		*get_next_room(t_stuff *u, int i)
{
	int		index;
	t_path	*new;
	int		j;

	j = 0;
	index = 1;
	new = 0;
	while (check_pre_room(u, index) || u->solve[i][index] == 0)
	{
		while (u->solve[i][index] != 1 || check_pre_room(u, index))
		{
			index++;
			if (index > u->room_num)
				return (0);
		}
	}
	u->solve[i][index] = 0;
	u->solve[index][i] = 0;
	new = (t_path*)malloc(sizeof(t_path));
	new->current_room = index;
	new->ant = 0;
	new->next = 0;
	return (new);
}

int			get_path(t_stuff *u)
{
	t_path	*temp;
	int		index;

	initialize_var(u);
	while (u->curr->current_room != u->room_num)
	{
		temp = u->path;
		index = u->curr->current_room;
		u->curr->next = get_next_room(u, index);
		if (u->curr->next == 0)
		{
			if (u->prev != u->curr)
				free(u->curr);
			u->curr = u->prev;
			u->prev = get_previous(u->path, u->curr->current_room, u->prev);
			if (u->prev == u->curr && check_for_incomplete(u) == 1)
				return (-5);
		}
		else
		{
			u->prev = u->curr;
			u->curr = u->curr->next;
		}
	}
	return (0);
}

t_path		*get_previous(t_path *path, int index, t_path *prev)
{
	while (path->next)
	{
		if (path->next->current_room == index)
			return (path);
		path = path->next;
	}
	return (prev);
}

void		initialize_var(t_stuff *u)
{
	u->path = (t_path*)malloc(sizeof(t_path));
	u->path->current_room = 0;
	u->path->next = 0;
	u->path->ant = 0;
	u->curr = u->path;
	u->prev = u->curr;
}
