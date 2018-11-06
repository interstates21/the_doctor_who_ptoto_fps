/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:29:04 by okupin            #+#    #+#             */
/*   Updated: 2018/03/30 21:29:05 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			init_for_each_x(t_world *e, int x)
{
	double tmp1;
	double tmp2;

	tmp1 = e->raydir.x;
	tmp2 = e->raydir.y;
	e->x_to_cam = 2 * x / (double)(W) - 1;
	e->raydir.x = e->dir.x + e->plane.x * e->x_to_cam;
	e->raydir.y = e->dir.y + e->plane.y * e->x_to_cam;
	e->map.x = (int)e->player.x;
	e->map.y = (int)e->player.y;
	e->delta.x = sqrt(1 + (e->raydir.y * e->raydir.y)
	/ (e->raydir.x * e->raydir.x));
	e->delta.y = sqrt(1 + (e->raydir.x * e->raydir.x)
	/ (e->raydir.y * e->raydir.y));
}

static void			init_step(t_world *e)
{
	if (e->raydir.x >= 0)
	{
		e->step.x = 1;
		e->distgrid.x = (e->map.x + 1 - e->player.x) * e->delta.x;
	}
	else
	{
		e->step.x = -1;
		e->distgrid.x = (e->player.x - e->map.x) * e->delta.x;
	}
	if (e->raydir.y >= 0)
	{
		e->step.y = 1;
		e->distgrid.y = (e->map.y + 1 - e->player.y) * e->delta.y;
	}
	else
	{
		e->step.y = -1;
		e->distgrid.y = (e->player.y - e->map.y) * e->delta.y;
	}
}

static int			cast_ray(t_world *e)
{
	if (e->distgrid.x < e->distgrid.y)
	{
		e->side = 'h';
		e->map.x += e->step.x;
		e->distgrid.x += e->delta.x;
	}
	else
	{
		e->side = 'v';
		e->map.y += e->step.y;
		e->distgrid.y += e->delta.y;
	}
	if (e->matrix[e->map.y][e->map.x] > 0)
		return (1);
	return (0);
}

void				ft_redraw(t_world *e)
{
	int		x;

	ft_bzero(e->data, (W * H * e->bpp));
	mlx_clear_window(e->mlx, e->win);
	x = 0;
	while (x < W)
	{
		init_for_each_x(e, x);
		init_step(e);
		while ((e->map.x > 0 && e->map.x < e->columns)
		&& (e->map.y > 0 && e->map.y < e->rows))
			if (cast_ray(e) == 1)
				break ;
		if (e->side == 'h')
			e->perpdist = (e->map.x - e->player.x
			+ (1 - e->step.x) / 2) / e->raydir.x;
		else
			e->perpdist = (e->map.y - e->player.y
			+ (1 - e->step.y) / 2) / e->raydir.y;
		e->lineheight = (int)(H / e->perpdist);
		e->linestart = -e->lineheight / 3 + H / 2;
		e->lineend = e->lineheight / 3 + H / 2;
		all_lines(e, x);
		x++;
	}
}

int					play_in_time(t_world *e)
{
	if (e->move_forw == 1)
		player_move_forw(e);
	if (e->move_back == 1)
		player_move_back(e);
	if (e->rot_left)
	{
		e->plane = t_rotate_z(e->plane, e->r_speed);
		e->dir = t_rotate_z(e->dir, e->r_speed);
	}
	if (e->rot_right)
	{
		e->plane = t_rotate_z(e->plane, -e->r_speed);
		e->dir = t_rotate_z(e->dir, -e->r_speed);
	}
	ft_redraw(e);
	if (e->color_mode == 1 || e->move_forw == 1)
		ft_interface(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
