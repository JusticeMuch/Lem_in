/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:07:14 by jronald           #+#    #+#             */
/*   Updated: 2018/09/25 09:48:33 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leming.h"

int		main(void)
{
	int			ret;
	t_stuff		*u;

	u = (t_stuff*)malloc(sizeof(t_stuff));
	ret = get_data(u);
	if (ret < 0)
		return (error_message_display(ret, u));
	ret = fill_algo_array(u);
	ret = get_path(u);
	if (ret < 0)
		return (error_message_display(ret, u));
	return (print_out(u));
}

int		get_data(t_stuff *u)
{
	char	*line;
	int		i;

	i = -1;
	line = ft_strnew(0);
	get_next_line(0, &line);
	if (check_ants(line) == 1 || ft_atoi(line) <= 0)
		return (-6);
	u->ants = ft_atoi(line);
	u->rooms = 0;
	u->solve = 0;
	u->room_c = 0;
	u->path = 0;
	u->room_num = 0;
	u->last = 0;
	u->end = 0;
	u->file = 0;
	while (++i < 100)
	{
		u->rc[i][0] = 0;
		u->rc[i][1] = 0;
	}
	u->rooms = (char**)malloc(sizeof(char*) * 100);
	u->rooms[0] = 0;
	return (read_file(u, &line));
}

void	print_path(t_stuff *u)
{
	t_path	*temp;

	temp = u->path;
	while (temp)
	{
		if (temp->ant > 0 && temp->ant <= u->ants)
		{
			ft_putchar('L');
			ft_putnbr(temp->ant);
			ft_putchar('-');
			ft_putstr(u->rooms[temp->current_room]);
			ft_putchar(' ');
		}
		temp = temp->next;
	}
	ft_putchar('\n');
}

void	print_output(t_stuff *u)
{
	int		ants;
	t_path	*t2;

	ants = 0;
	while (check_display(u->path, u) == 1 || ants == 0)
	{
		t2 = u->path;
		t2->ant = ++ants;
		while (t2->next)
		{
			if (t2->ant > 0)
				t2->next->ant = t2->ant - 1;
			t2 = t2->next;
		}
		print_path(u);
	}
}

int		display_end(t_stuff *u, char *msg)
{
	if (u->file != 0)
		free_arr(&(u->file));
	if (u->rooms != 0)
		free(u->rooms);
	free(u);
	ft_putstr(msg);
	return (1);
}
