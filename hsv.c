/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hcv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 03:40:37 by okupin            #+#    #+#             */
/*   Updated: 2018/03/01 03:40:38 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void		hsv0to3(double v, t_px *px, t_hsv *hsv)
{
	if (hsv->i == 0)
	{
		px->r = v;
		px->g = hsv->t;
		px->b = hsv->p;
	}
	else if (hsv->i == 1)
	{
		px->r = hsv->q;
		px->g = v;
		px->b = hsv->p;
	}
	else if (hsv->i == 2)
	{
		px->r = hsv->p;
		px->g = v;
		px->b = hsv->t;
	}
}

static	void		hsv3to5(double v, t_px *px, t_hsv *hsv)
{
	if (hsv->i == 3)
	{
		px->r = hsv->p;
		px->g = hsv->q;
		px->b = v;
	}
	else if (hsv->i == 4)
	{
		px->r = hsv->t;
		px->g = hsv->p;
		px->b = v;
	}
	else
	{
		px->r = v;
		px->g = hsv->p;
		px->b = hsv->q;
	}
}

void				ft_hsvtorgb(t_px *px, float h, float s, float v)
{
	t_hsv	hsv;

	if (h < 0)
		h += 360;
	if (h >= 360)
		h -= 360;
	h = h / 60.0;
	hsv.i = floor(h);
	hsv.f = h - hsv.i;
	hsv.p = v * (1 - s);
	hsv.q = v * (1 - s * hsv.f);
	hsv.t = v * (1 - s * (1 - hsv.f));
	if (hsv.i >= 0 && hsv.i < 3)
		hsv0to3(v, px, &hsv);
	else
		hsv3to5(v, px, &hsv);
	px->r *= 255;
	px->g *= 255;
	px->b *= 255;
}
