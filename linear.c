/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 22:35:48 by okupin            #+#    #+#             */
/*   Updated: 2018/03/22 22:45:19 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_dpoint	t_rotate_x(t_dpoint p, double angle)
{
	double temp;

	angle = angle * M_PI / 180.0;
	temp = p.y;
	p.y = p.y * cos(angle) - p.z * sin(angle);
	p.z = temp * sin(angle) + p.z * cos(angle);
	return (p);
}

t_dpoint	t_rotate_y(t_dpoint p, double angle)
{
	double temp;

	angle = angle * M_PI / 180.0;
	temp = p.z;
	p.z = p.z * cos(angle) - p.x * sin(angle);
	p.x = temp * sin(angle) + p.x * cos(angle);
	return (p);
}

t_dpoint	t_rotate_z(t_dpoint p, double angle)
{
	double temp;

	temp = p.x;
	p.x = p.x * cos(angle) - p.y * sin(angle);
	p.y = temp * sin(angle) + p.y * cos(angle);
	return (p);
}

t_dpoint	t_translate(t_dpoint p, int tx, int ty)
{
	p.x += tx;
	p.y += ty;
	return (p);
}

t_dpoint	t_linear(t_world *wrd, t_dpoint p)
{
	t_dpoint tmp;

	tmp.x = p.x;
	tmp.y = p.y;
	tmp.z = p.z;
	p.x = wrd->scale * ((tmp.x - wrd->columns / 2)
	* cos(wrd->angle_y)
	* cos(wrd->angle_z) - (tmp.y - wrd->rows / 2)
	* sin(wrd->angle_z) * cos(wrd->angle_y) - tmp.z
	* wrd->depth * sin(wrd->angle_y));
	p.y = wrd->scale * ((tmp.x - wrd->columns / 2)
	* (-sin(wrd->angle_x) * sin(wrd->angle_y)
	* cos(wrd->angle_z) + cos(wrd->angle_x) * sin(wrd->angle_z))
	+ (p.y - wrd->rows / 2) * (sin(wrd->angle_x) * sin(wrd->angle_y)
	* sin(wrd->angle_z) +
	cos(wrd->angle_x) * cos(wrd->angle_z)) + tmp.z
	* wrd->depth * (-sin(wrd->angle_x)) * cos(wrd->angle_y));
	return (p);
}
