/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:06:20 by okupin            #+#    #+#             */
/*   Updated: 2018/03/31 23:06:20 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_imgcpy(t_world *e, int x, int y)
{
	if (((x > 0 && x < W) && (y > 0 && y < H))
	&& ((e->j < e->ball.xpm_w) && (e->i < e->ball.xpm_h)))
	{
		if (e->ball.data[(e->j * 4) + (e->i * e->ball.xpm_w * 4) + 2] != 0
			&& e->ball.data[(e->j * 4)
			+ (e->i * e->ball.xpm_w * 4) + 2] != 1)
		{
			e->data[(x * 4) + (y * W * 4) + 2] =
			e->ball.data[(e->j * 4) + (e->i * e->ball.xpm_w * 4) + 2];
			e->data[(x * 4) + (y * W * 4) + 1] =
			e->ball.data[(e->j * 4) + (e->i * e->ball.xpm_w * 4) + 1];
			e->data[(x * 4) + (y * W * 4)] =
			e->ball.data[(e->j * 4) + (e->i * e->ball.xpm_w * 4)];
		}
	}
}

void			ft_interface(t_world *e)
{
	int x;
	int y;

	y = H / 5;
	e->i = 0;
	while (e->i < e->ball.xpm_h)
	{
		e->j = 0;
		x = W - W / 3;
		while (e->j < e->ball.xpm_w)
		{
			ft_imgcpy(e, x, y);
			e->j++;
			x++;
		}
		e->i++;
		y++;
	}
}
