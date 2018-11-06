/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:35:21 by okupin            #+#    #+#             */
/*   Updated: 2018/03/22 12:36:19 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <stdio.h>

# define W 1024
# define H 648
# define BRICKW 1024
# define BRICKH 1024
# define BALLSZ 96;
# define HW W / 2
# define HH H / 2
# define H_BLUE 200
# define MXY wrd->max_y
# define MNY wrd->min_y
# define MNX wrd->min_x
# define MXX wrd->max_x
# define RTOD(RAD) (RAD * 180 / PI)
# define DTOR(D) (D * PI / 180)
# define X0 wrd->p0.x
# define Y0 wrd->p0.y
# define Y1 wrd->p1.y
# define X1 wrd->p1.x
# define R	e->rows
# define C	e->columns
# define OFST_Y (e->player.y + e->dir.y * e->m_speed)
# define OFST_X (e->player.x + e->dir.x * e->m_speed)
# define NOFST_Y (e->player.y - e->dir.y * e->m_speed)
# define NOFST_X (e->player.x - e->dir.x * e->m_speed)
# define K_UP 13
# define K_DOWN 1
# define K_LEFT 0
# define K_RIGHT 2
# define K_Q 12
# define K_TAB 48
# define K_PLUS 69
# define K_MINUS 78
# define K_1 18
# define K_2 19
# define K_3 20
# define K_W 13
# define M_MOTION (1L << 6)
# define K_Z 6
# define K_X 7
# define K_R 15
# define L_CLICK 1
# define R_CLICK 2
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define K_PRESS 2
# define K_PRESS_MASK (1L<<0)

typedef struct	s_mapping
{
	float		in_min;
	float		in_max;
	float		out_min;
	float		out_max;
}				t_mapping;

typedef struct	s_px
{
	double		r;
	double		g;
	double		b;
}				t_px;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_dpoint
{
	double		x;
	double		y;
	double		z;
}				t_dpoint;

typedef struct	s_hsv
{
	float		p;
	float		q;
	float		t;
	float		f;
	int			i;
}				t_hsv;

typedef struct	s_img
{
	void		*img;
	int			xpm_w;
	int			xpm_h;
	int			en;
	int			ln;
	int			bpp;
	char		*data;
}				t_img;

typedef struct	s_world
{
	void		*mlx;
	void		*win;
	int			linedx;
	int			linedy;
	int			linesx;
	int			linesy;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	t_point		p0;
	t_point		p1;
	int			en;
	int			bpp;
	int			ln;
	char		*data;
	t_img		background;
	t_img		background2;
	t_img		ball;
	void		*img;
	int			fd;
	int			rows;
	int			columns;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	int			depth;
	int			scale;
	t_px		px;
	t_px		px_roof;
	t_px		px_floor;
	char		*name;
	double		x_to_cam;
	double		perpdist;
	int			linestart;
	int			lineend;
	int			lineheight;
	t_dpoint	player;
	t_dpoint	plane;
	t_dpoint	dir;
	t_dpoint	raydir;
	t_point		map;
	t_dpoint	delta;
	t_dpoint	distgrid;
	int			**matrix;
	t_point		step;
	double		m_speed;
	double		r_speed;
	char		side;
	int			move_forw;
	int			move_back;
	int			rot_right;
	int			rot_left;
	int			color_mode;
	t_dpoint	img_pos;
	int			i;
	int			j;
}				t_world;

t_dpoint		t_linear(t_world *wrd, t_dpoint p);
t_dpoint		t_translate(t_dpoint p, int tx, int ty);
t_dpoint		t_rotate_z(t_dpoint p, double angle);
t_dpoint		t_rotate_y(t_dpoint p, double angle);
t_dpoint		t_rotate_x(t_dpoint p, double angle);
void			random_color(t_world *e);
void			color_mode_1(t_world *e);
t_px			fill_px(int r, int g, int b);
t_mapping		ft_fill_map(float a, float b, float c, float d);
float			ft_map(float x, t_mapping m);
int				ft_mlx(t_world *wrd);
void			ft_hsvtorgb(t_px *px, float h, float s, float v);
void			ft_px(t_world *wrd, int x, int y, t_px px);
void			ft_redraw(t_world *e);
int				ft_read(t_world *wrd);
int				ft_count_all(t_world *wrd, int checklen);
int				key_listener(int keycode, t_world *e);
void			all_lines(t_world *e, int x);
void			ft_line(t_world *wrd);
int				to_i(double a, int size);
int				play_in_time(t_world *e);
void			player_move_back(t_world *e);
void			player_move_forw(t_world *e);
void			ft_interface(t_world *e);
int				ft_exit(void);

#endif
