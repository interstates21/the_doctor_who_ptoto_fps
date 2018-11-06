/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:14:10 by okupin            #+#    #+#             */
/*   Updated: 2018/03/04 18:14:11 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_px(t_world *wrd, int x, int y, t_px px)
{
	if ((x > 0 && x < W) && (y > 0 && y < H))
	{
		wrd->data[(x * 4) + (y * W * 4) + 2] = px.r;
		wrd->data[(x * 4) + (y * W * 4) + 1] = px.g;
		wrd->data[(x * 4) + (y * W * 4)] = px.b;
	}
}

t_px			fill_px(int r, int g, int b)
{
	t_px	ret;

	ret.r = r;
	ret.g = g;
	ret.b = b;
	return (ret);
}
