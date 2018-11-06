/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:28:52 by okupin            #+#    #+#             */
/*   Updated: 2018/03/30 21:28:53 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		vertical_dark(t_px *px)
{
	px->r /= 2;
	px->g /= 2;
	px->b /= 2;
}

void		random_color(t_world *e)
{
	int ran;

	ran = rand();
	if (e->matrix[e->map.y][e->map.x] == 2)
	{
		if (e->side == 'h')
			e->px = fill_px(ran, ran, ran);
		else
			e->px = fill_px(ran % 150, ran % 150, ran % 150);
	}
	else if (e->matrix[e->map.y][e->map.x] == 3)
		e->px = fill_px(255, 255, 255);
	else
	{
		if (e->side == 'h')
			e->px = fill_px(25, 25, 25);
		else
			e->px = fill_px(15, 15, 15);
	}
}

void		color_mode_1(t_world *e)
{
	int check;

	check = e->matrix[e->map.y][e->map.x];
	if (check == 2 || check == 3)
	{
		e->px = fill_px(255, 255, 0);
	}
	else if (check == 4)
		e->px = fill_px(255, 255, 255);
	else if (check == 5)
		e->px = fill_px(0, 0, 0);
	else
	{
		e->px = fill_px(40, 40, 40);
	}
	if (e->side == 'v')
		vertical_dark(&e->px);
	e->px_roof = fill_px(0, 0, 0);
	e->px_floor = fill_px(100, 60, 60);
}
