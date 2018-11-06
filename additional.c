/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 22:13:09 by okupin            #+#    #+#             */
/*   Updated: 2018/03/30 22:13:09 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		to_i(double a, int size)
{
	int ret;

	if (a <= 1.0)
		ret = 1;
	if (a > (double)size - 1)
		ret = size - 1;
	else
		ret = (int)a;
	return (ret);
}

int		ft_exit(void)
{
	exit(1);
	return (0);
}
