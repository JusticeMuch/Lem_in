/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:15:31 by jronald           #+#    #+#             */
/*   Updated: 2018/09/25 09:48:51 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leming.h"

int		export_file_to_array(t_stuff *u, char **line)
{
	int i;

	i = 0;
	u->file = (char**)malloc(sizeof(char*) * 1000);
	while (get_next_line(0, line) > 0)
	{
		u->file[i] = ft_strdup(*line);
		ft_strdel(line);
		i++;
	}
	if (i < 4)
		return (-7);
	u->file[i] = 0;
	return (0);
}

int		error_message_display(int ret, t_stuff *u)
{
	if (ret == -1)
		return (display_end(u, "Error - incorrect command.\n"));
	else if (ret == -2)
		return (display_end(u, "Error - incorrect room data input.\n"));
	else if (ret == -3)
		return (display_end(u, "Error - incorrect room connection data\n"));
	else if (ret == -4)
		return (display_end(u, "Error - no start/end room data.\n"));
	else if (ret == -5)
		return (display_end(u, "Error - no path found.\n"));
	else if (ret == -6)
		return (display_end(u, "Error - incorrect ants input data\n"));
	else if (ret == -7)
		return (display_end(u, "Error - too little data.\n"));
	return (0);
}

int		print_out(t_stuff *u)
{
	int j;

	j = -1;
	ft_putnbr(u->ants);
	ft_putchar('\n');
	while (u->file[++j])
	{
		ft_putstr(u->file[j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	print_output(u);
	return (display_end(u, 0));
}

int		check_ants(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (1);
		str++;
	}
	return (0);
}

int		check_display(t_path *u, t_stuff *t)
{
	t_path *temp;

	temp = u;
	while (temp)
	{
		if (temp->ant > 0 && temp->ant <= t->ants)
			return (1);
		temp = temp->next;
	}
	return (0);
}
