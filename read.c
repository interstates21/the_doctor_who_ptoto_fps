/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:17:18 by okupin            #+#    #+#             */
/*   Updated: 2018/02/01 20:17:25 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	int			check_bound(t_world *e)
{
	int x;
	int y;

	y = 0;
	while (y < e->rows)
	{
		if (e->matrix[y][0] == 0 || e->matrix[y][e->columns - 1] == 0)
			return (-1);
		y++;
	}
	x = 0;
	while (x < e->columns)
	{
		if (e->matrix[0][x] == 0 || e->matrix[e->rows - 1][x] == 0)
			return (-1);
		x++;
	}
	return (1);
}

static	void		ft_fill_struct(int *ret, int i, char *line)
{
	ret[i] = line[i] - '0';
}

static	int			*ft_read_line(t_world *e)
{
	char	*line;
	int		*ret;
	int		i;

	i = 0;
	if ((ret = (int*)malloc(sizeof(int) * e->columns)) == NULL)
		return (NULL);
	if (get_next_line(e->fd, &line) < 0)
	{
		ft_putstr("NULL");
		return (NULL);
	}
	i = 0;
	while (i < e->columns)
	{
		ft_fill_struct(ret, i, line);
		i++;
	}
	free(line);
	return (ret);
}

int					ft_read(t_world *e)
{
	int i;

	i = 0;
	if ((e->fd = open(e->name, O_RDONLY)) == -1)
		return (-1);
	if ((e->matrix = (int**)malloc(sizeof(int*)
		* e->rows + 1)) == NULL)
		return (-1);
	while (i < e->rows)
	{
		if (!(e->matrix[i] = ft_read_line(e)))
			return (-1);
		i++;
	}
	e->matrix[i] = NULL;
	if (check_bound(e) == -1)
	{
		ft_putstr("invalid map: empty borders");
		return (-1);
	}
	close(e->fd);
	return (0);
}
