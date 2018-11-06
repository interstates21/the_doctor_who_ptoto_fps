/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:21:51 by okupin            #+#    #+#             */
/*   Updated: 2018/03/23 20:22:01 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	int		ft_count_ch(char *line, t_world *wrd)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] < '0' || line[i] > '9'))
		{
			ft_putstr("char");
			return (-1);
		}
		len++;
		i++;
	}
	wrd->columns = len;
	return (0);
}

int				ft_count_all(t_world *wrd, int checklen)
{
	char	*line;
	int		i;

	wrd->columns = 0;
	i = 0;
	while (get_next_line(wrd->fd, &line) > 0)
	{
		if (ft_count_ch(line, wrd) == -1)
			return (-1);
		if (wrd->rows == 0)
			checklen = wrd->columns;
		if (line)
			free(line);
		if (checklen != wrd->columns)
			return (-1);
		i++;
		wrd->rows++;
	}
	if (wrd->columns < 3 || wrd->rows < 3)
		return (-1);
	return (0);
}
