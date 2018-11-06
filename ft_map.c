/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:59:24 by okupin            #+#    #+#             */
/*   Updated: 2018/03/05 17:59:44 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mapping	ft_fill_map(float a, float b, float c, float d)
{
	t_mapping m;

	m.in_min = a;
	m.in_max = b;
	m.out_min = c;
	m.out_max = d;
	return (m);
}

float		ft_map(float x, t_mapping m)
{
	return (x - m.in_min) * (m.out_max - m.out_min)
	/ (m.in_max - m.in_min) + m.out_min;
}
