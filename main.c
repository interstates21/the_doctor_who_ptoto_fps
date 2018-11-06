/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:35:00 by okupin            #+#    #+#             */
/*   Updated: 2018/03/22 12:35:12 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_xpm_image(t_world *e)
{
	e->background.img =
	mlx_xpm_file_to_image(e->mlx, "balls/stars.xpm",
	&e->background.xpm_w, &e->background.xpm_h);
	if ((e->background.data = mlx_get_data_addr(e->background.img,
	&e->background.bpp, &e->background.ln,
	&e->background.en)) == NULL)
		return (-1);
	e->background2.img =
	mlx_xpm_file_to_image(e->mlx, "balls/brick.xpm",
	&e->background2.xpm_w, &e->background2.xpm_h);
	if ((e->background2.data = mlx_get_data_addr(e->background2.img,
	&e->background2.bpp, &e->background2.ln,
	&e->background2.en)) == NULL)
		return (-1);
	e->ball.img =
	mlx_xpm_file_to_image(e->mlx, "balls/b5.xpm",
	&e->ball.xpm_w, &e->ball.xpm_h);
	if ((e->ball.data = mlx_get_data_addr(e->ball.img,
	&e->ball.bpp, &e->ball.ln, &e->ball.en)) == NULL)
		return (-1);
	return (0);
}

void			ft_print_error(int action)
{
	if (action == 2)
		ft_putstr(":CREATION ERROR\n");
	if (action == 1)
	{
		ft_putstr("Usage: ./wolf3d [../mapname.map]");
	}
}

static void		init_game(t_world *e)
{
	e->player.x = 2;
	e->player.y = 2;
	e->dir.x = -1;
	e->dir.y = 0;
	e->plane.x = 0;
	e->plane.y = 0.66;
	e->m_speed = 0.1;
	e->r_speed = 0.1;
	e->move_forw = 0;
	e->move_back = 0;
	e->rot_left = 0;
	e->rot_right = 0;
	e->background.xpm_w = W;
	e->background.xpm_h = H;
	e->background2.xpm_w = BRICKW;
	e->background2.xpm_h = BRICKH;
	e->color_mode = 0;
	get_xpm_image(e);
	ft_putstr("I am the DOCTOR!");
}

static int		create_world(char *argv)
{
	t_world *e;

	if ((e = (t_world*)malloc(sizeof(t_world))) == NULL)
		return (-1);
	if ((e->fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	e->name = argv;
	if (ft_count_all(e, 0) == -1)
		return (-1);
	close(e->fd);
	if (ft_read(e) == -1)
		return (-1);
	if (ft_mlx(e) == -1)
		return (-1);
	init_game(e);
	mlx_do_key_autorepeatoff(e->mlx);
	mlx_loop_hook(e->mlx, play_in_time, e);
	mlx_hook(e->win, K_PRESS, K_PRESS_MASK, key_listener, e);
	mlx_hook(e->win, 17, 0, ft_exit, e);
	mlx_key_hook(e->win, key_listener, e);
	mlx_loop(e->mlx);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_print_error(1);
		return (0);
	}
	if (ft_strstr(argv[1], ".map") == NULL)
	{
		ft_print_error(1);
		return (0);
	}
	if (create_world(argv[1]) == -1)
	{
		ft_print_error(2);
		return (0);
	}
	return (0);
}
