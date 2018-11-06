/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:30:00 by okupin            #+#    #+#             */
/*   Updated: 2018/03/30 21:30:00 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			ft_roofcpy(t_world *e, int x, int y, int n)
{
	e->img_pos.x = ((x * 4) + n);
	e->img_pos.y = (y * e->background.xpm_w * 4);
	if (((x > 0 && x < W) && (y > 0 && y < H))
	&& ((x < e->background.xpm_w) && (y < e->background.xpm_h)))
	{
		e->data[(x * 4) + (y * W * 4) + 2] =
		e->background.data[(int)e->img_pos.x + (int)e->img_pos.y + 2];
		e->data[(x * 4) + (y * W * 4) + 1] =
		e->background.data[(int)e->img_pos.x + (int)e->img_pos.y + 1];
		e->data[(x * 4) + (y * W * 4)] =
		e->background.data[(int)e->img_pos.x + (int)e->img_pos.y];
	}
}

static	void		roof_line(t_world *e, int y_start, int y_end, int x)
{
	static	int		n = 1;

	if (e->rot_left || e->rot_right)
		n = (n - 4) % (e->background.xpm_w * 4);
	while (y_start < y_end)
	{
		if (e->color_mode == 1 || e->move_forw == 1)
			ft_roofcpy(e, x, y_start, n);
		else
			ft_px(e, x, y_start, e->px_roof);
		y_start++;
	}
}

static void			floor_line(t_world *e, int y_start, int y_end, int x)
{
	int i;

	i = 0;
	while (y_start < y_end)
	{
		if (e->color_mode == 1 || e->move_forw == 1)
		{
			i = i >= 38 ? 38 : i + 1;
			e->px_floor = fill_px(i, i, i);
		}
		ft_px(e, x, y_start, e->px_floor);
		y_start++;
	}
}

void				all_lines(t_world *e, int x)
{
	int		y;

	y = e->linestart;
	y = y <= 1 ? 1 : y;
	if (e->lineend >= H)
		e->lineend = H - 1;
	color_mode_1(e);
	while (y <= e->lineend)
	{
		if (e->move_forw == 1 || e->color_mode == 1)
			random_color(e);
		ft_px(e, x, y, e->px);
		y++;
	}
	roof_line(e, 1, e->linestart, x);
	floor_line(e, e->lineend, (H - 1), x);
}
