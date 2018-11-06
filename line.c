/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:09:11 by okupin            #+#    #+#             */
/*   Updated: 2018/03/23 18:09:21 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void		wrd_line_params(t_world *wrd)
{
	wrd->linedx = abs(X1 - X0);
	wrd->linedy = abs(Y1 - Y0);
	wrd->linesx = X1 >= X0 ? 1 : -1;
	wrd->linesy = Y1 >= Y0 ? 1 : -1;
}

static	void		ft_draw_dx(t_world *wrd)
{
	int error;
	int i;
	int x;
	int y;

	error = (wrd->linedy << 1) - wrd->linedx;
	x = X0 + wrd->linesx;
	y = Y0;
	i = 1;
	ft_px(wrd, X0, Y0, wrd->px);
	while (i <= wrd->linedx)
	{
		if (error > 0)
		{
			error += (wrd->linedy - wrd->linedx) << 1;
			y += wrd->linesy;
		}
		else
			error += wrd->linedy << 1;
		ft_px(wrd, x, y, wrd->px);
		x += wrd->linesx;
		i++;
	}
}

static	void		ft_draw_dy(t_world *wrd)
{
	int error;
	int i;
	int x;
	int y;

	error = (wrd->linedx << 1) - wrd->linedy;
	y = Y0 + wrd->linesy;
	x = X0;
	i = 1;
	ft_px(wrd, X0, Y0, wrd->px);
	while (i <= wrd->linedy)
	{
		if (error > 0)
		{
			error += (wrd->linedx - wrd->linedy) << 1;
			x += wrd->linesx;
		}
		else
			error += wrd->linedx << 1;
		ft_px(wrd, x, y, wrd->px);
		y += wrd->linesy;
		i++;
	}
}

void				ft_line(t_world *wrd)
{
	wrd_line_params(wrd);
	if (wrd->linedy <= wrd->linedx)
		ft_draw_dx(wrd);
	else
		ft_draw_dy(wrd);
}
