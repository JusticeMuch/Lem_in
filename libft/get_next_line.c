/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:08:43 by jronald           #+#    #+#             */
/*   Updated: 2018/09/11 12:46:23 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*read_line(const int fd, char **buff, int *ret)
{
	char	temp[BUFF_SIZE + 1];
	char	*temp2;

	temp2 = *buff;
	*ret = read(fd, temp, BUFF_SIZE);
	temp[*ret] = '\0';
	*buff = ft_strjoin(*buff, temp);
	ft_strdel(&temp2);
	return (*buff);
}

static int			end_line(char ***line, char **buff)
{
	**line = ft_strdup(*buff);
	if (!**line)
		return (-1);
	ft_strdel(buff);
	return (1);
}

static int			newline_end(char ***line, char **buff, char **s)
{
	char *temp;

	temp = *buff;
	**line = ft_strsub(temp, 0, ft_strlen(temp) - ft_strlen(*s));
	*buff = ft_strdup(*s + 1);
	ft_strdel(&temp);
	if (!(*line))
		return (-1);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*buff;
	int				ret;
	char			*s;

	if (!buff)
		buff = ft_strnew(0);
	ret = 1;
	if (fd < 0 || BUFF_SIZE < 0 || !buff || read(fd, buff, 0) < 0)
		return (-1);
	while (ret > 0)
	{
		if ((s = ft_strchr(buff, '\n')) != NULL)
			return (newline_end(&line, &buff, &s));
		buff = read_line(fd, &buff, &ret);
		if (!buff)
			return (-1);
	}
	ft_strdel(&s);
	if (ret < 0)
		return (-1);
	else if (buff[0] == '\0' && ret == 0)
		return (0);
	else
		return (end_line(&line, &buff));
}
