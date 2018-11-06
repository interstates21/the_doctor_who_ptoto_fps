/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:29:14 by okupin            #+#    #+#             */
/*   Updated: 2018/03/30 21:29:15 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			player_move_forw(t_world *e)
{
	if (e->matrix[to_i(e->player.y, R)][to_i(OFST_X, C)] == 0)
		e->player.x += e->dir.x * e->m_speed;
	if (e->matrix[to_i(OFST_Y, R)][to_i(e->player.x, C)] == 0)
		e->player.y += e->dir.y * e->m_speed;
}

void			player_move_back(t_world *e)
{
	if (e->matrix[to_i(e->player.y, R)][to_i(NOFST_X, C)] == 0)
		e->player.x -= e->dir.x * e->m_speed;
	if (e->matrix[to_i(NOFST_Y, R)][to_i(e->player.x, C)] == 0)
		e->player.y -= e->dir.y * e->m_speed;
}

int				key_listener(int keycode, t_world *e)
{
	if (keycode == 53)
		exit(1);
	if (keycode == K_TAB)
		e->color_mode = (e->color_mode + 1) % 2;
	if (keycode == K_UP)
		e->move_forw = (e->move_forw + 1) % 2;
	if (keycode == K_DOWN)
		e->move_back = (e->move_back + 1) % 2;
	if (keycode == K_RIGHT)
		e->rot_right = (e->rot_right + 1) % 2;
	if (keycode == K_LEFT)
		e->rot_left = (e->rot_left + 1) % 2;
	return (0);
}
