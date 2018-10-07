/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leming.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:24:10 by jronald           #+#    #+#             */
/*   Updated: 2018/09/20 18:19:33 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMING_H
# define LEMING_H

# include "libft.h"
# include "get_next_line.h"

typedef struct		s_path
{
	int				current_room;
	int				ant;
	struct s_path	*next;
}					t_path;

typedef struct		s_stuff
{
	int				ants;
	char			**rooms;
	int				**solve;
	int				rc[100][2];
	int				room_c;
	t_path			*path;
	int				room_num;
	char			*last;
	int				start;
	int				end;
	char			**file;
	t_path			*prev;
	t_path			*curr;
}					t_stuff;

int					read_file(t_stuff *u, char **temp);
int					get_rooms(t_stuff *u, char *line);
int					get_hashes(t_stuff *u, char **line, int *ind);
void				free_arr(char ***arr);
int					get_rooms_2(char ***temp, char **res);
int					check_pre_room(t_stuff *u, int ind);
int					get_path(t_stuff *u);
int					get_data(t_stuff *u);
int					export_file_to_array(t_stuff *u, char **line);
int					error_message_display(int ret, t_stuff *u);
int					display_end(t_stuff *u, char *msg);
void				print_path(t_stuff *u);
void				print_output(t_stuff *u);
int					print_out(t_stuff *u);
int					check_for_incomplete(t_stuff *u);
int					get_index(t_stuff *u, char *temp);
int					get_room_connections(t_stuff *u, char *line);
int					check_ants(char *str);
int					fill_algo_array(t_stuff *u);
t_path				*get_previous(t_path *path, int index, t_path *prev);
int					check_display(t_path *u, t_stuff *t);
void				initialize_var(t_stuff *u);
void				set_zero(int *val1, int *val2);
#endif
