/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:32:18 by okupin            #+#    #+#             */
/*   Updated: 2018/03/23 18:32:35 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_img(t_world *wrd)
{
	if ((wrd->img = mlx_new_image(wrd->mlx, W, H)) == NULL)
		return (-1);
	if ((wrd->data = mlx_get_data_addr(wrd->img,
	&wrd->bpp, &wrd->ln, &wrd->en)) == NULL)
		return (-1);
	wrd->bpp /= 8;
	return (0);
}

int		ft_mlx(t_world *wrd)
{
	if ((wrd->mlx = mlx_init()) == NULL)
		return (-1);
	if ((wrd->win = mlx_new_window(wrd->mlx, W, H, wrd->name)) == NULL)
		return (-1);
	if ((ft_img(wrd) == -1))
		return (-1);
	return (0);
}
