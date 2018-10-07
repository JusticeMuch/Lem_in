/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 19:21:25 by jronald           #+#    #+#             */
/*   Updated: 2018/09/25 09:53:09 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leming.h"

int		read_file(t_stuff *u, char **temp)
{
	int		ret;
	int		i;
	int		j;

	j = -1;
	ret = export_file_to_array(u, temp);
	while (u->file[++j] && ret >= 0)
	{
		if (u->file[j][0] == '#')
			ret = get_hashes(u, u->file, &j);
		else if (u->file[j])
		{
			i = 0;
			while (u->file[j][i] && (u->file[j][i] != '-'
						&& u->file[j][i] != 32))
				i++;
			if (u->file[j][i] == 32 && i != 0)
				ret = get_rooms(u, u->file[j]);
			else if (u->file[j][i] == '-' && i != 0)
				ret = get_room_connections(u, u->file[j]);
			else
				ret = -7;
		}
	}
	return (ret);
}

int		get_rooms(t_stuff *u, char *line)
{
	char	**temp;
	int		j;

	if (line[0] == 'L')
		return (-2);
	temp = ft_strsplit(line, ' ');
	j = (u->start == 1 && u->rooms[0] == 0)
		? 0 : (++u->room_num);
	j = (u->end == 1 && u->last == 0)
		? (--(u->room_num)) : j;
	if (u->end == 1 && u->last == 0)
		return (get_rooms_2(&temp, &(u->last)));
	else
		return (get_rooms_2(&temp, &(u->rooms[j])));
}

int		get_rooms_2(char ***temp, char **res)
{
	int		ret;
	int		i;
	char	**t;

	t = *temp;
	i = -1;
	ret = 0;
	while (t[++i])
	{
		*res = (i == 0) ? ft_strdup(t[i]) : *res;
		ret = (ft_isdigit(t[i][0]) != 1 && i == 1) ? -2 : ret;
		ret = (ft_isdigit(t[i][0]) != 1 && i == 2) ? -2 : ret;
		ret = (i > 2) ? -2 : ret;
	}
	free_arr(temp);
	return (ret);
}

int		get_hashes(t_stuff *u, char **line, int *ind)
{
	if (line[*ind][1] != '#')
		return (0);
	u->start = (ft_strcmp(line[*ind] + 2, "start") == 0) ? 1 : u->start;
	u->end = (ft_strcmp(line[*ind] + 2, "end") == 0) ? 1 : u->end;
	if (u->start == 1 || u->end == 1)
		return (get_rooms(u, line[++(*ind)]));
	if (ft_strcmp(line[*ind] + 2, "visual") == 0 ||
		ft_strcmp(line[*ind] + 2, "color") == 0)
		return (0);
	return (-1);
}

int		get_room_connections(t_stuff *u, char *line)
{
	char **temp;

	if (u->end == 0 || u->start == 0)
		return (-4);
	if (u->last != 0)
	{
		u->rooms[++(u->room_num)] = ft_strdup(u->last);
		ft_strdel(&(u->last));
	}
	temp = ft_strsplit(line, '-');
	if ((temp[0] == 0 || temp[1] == 0) || (get_index(u, temp[0]) == -1 ||
				get_index(u, temp[1]) == -1))
	{
		free_arr(&temp);
		return (-3);
	}
	(u->room_c)++;
	u->rc[u->room_c - 1][0] = get_index(u, temp[0]);
	u->rc[u->room_c - 1][1] = get_index(u, temp[1]);
	return (0);
}
