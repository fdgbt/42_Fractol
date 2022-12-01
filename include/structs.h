/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:47:33 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/23 22:47:36 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define D_MAN_PATH "./man/fractol.txt"
# define D_PI 3.14159265358979323846
# define D_SCREEN_RES 1000
# define D_HUD_RES 300
# define D_MOUSE_SENSI 5
# define D_OPT_MAX 20
# define D_FRACT_MAX 9
# define D_NAME_MAX 50
# define D_JULIA_MAX 8
# define D_MOD_MAX 6
# define D_PAL_MAX 20
# define D_COL_MAX 5
# define D_BKG_MAX 8
# define D_BKG_MENU 0x343D46
# define D_ITER_MAX 32
# define D_ITER_MIN 10
# define D_SSAA_MAX 8
# define D_THREADS 16

# include <pthread.h>
# include "mlx_int.h"
# include "libft.h"

typedef struct			s_grid
{
	double				x;
	double				y;
	int					iteration;
	int					red;
	int					green;
	int					blue;
}						t_grid;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_pthr
{
	int					start;
	int					end;
}						t_pthr;

typedef struct			s_rgb
{
	int					red;
	int					green;
	int					blue;
}						t_rgb;

typedef struct			s_hsv
{
	double				s;
	double				v;
	double				h;
	double				i;
	double				f;
	double				l;
	double				m;
	double				n;
}						t_hsv;

typedef struct			s_colors
{
	int					mode;
	int					palette;
	int					roll;
	int					bkg;
	int					bkg_pal;
	int					bkg_roll;
	int					rgb;
	int					red;
	int					green;
	int					blue;
	int					hsv;
	int					hue;
	int					saturation;
	int					value;
	int					psychedelic;
	int					epileptic;
	int					color_buddha;
	int					colors[D_PAL_MAX][D_COL_MAX];
	char				mode_name[D_MOD_MAX][15];
	char				mode_buddha[D_MOD_MAX][20];
	char				palette_name[D_PAL_MAX + 1][15];
}						t_colors;

typedef struct			s_mouse
{
	int					xold;
	int					yold;
	int					xcount;
	int					ycount;
	int					move_c;
	int					shift;
}						t_mouse;

typedef struct			s_zoom
{
	double				x1;
	double				deltax;
	double				dx1;
	double				dx2;
	double				y1;
	double				deltay;
	double				dy1;
	double				dy2;
	double				zoom;
}						t_zoom;

typedef struct			s_fractal
{
	double				xstart;
	double				xend;
	double				ystart;
	double				yend;
	double				scale_x;
	double				scale_y;
	double				offset_x;
	double				offset_y;
	int					border;
	int					zoom;
	int					julia_set;
	float				julia_c[D_JULIA_MAX][2];
	int					***buddha;
	t_complex			init;
}						t_fractal;

typedef struct			s_bresenham
{
	int					x;
	int					y;
	int					dx;
	int					dy;
	int					xincr;
	int					yincr;
	int					err;
	int					i;
}						t_bresenham;

typedef struct			s_imgx
{
	void				*img_ptr;
	int					*img_data;
	int					bpp;
	int					size_l;
	int					endian;
}						t_imgx;

typedef struct			s_conf
{
	char				opt_keys[D_OPT_MAX];
	int					opt[D_OPT_MAX];
	int					fract_number;
	char				fract_name[D_FRACT_MAX + 1][15];
	int					resolution;
	int					hud_res;
	int					hud_cmd;
	int					super_sampling;
	int					imax;
	int					imin;
	int					level;
	int					sample;
	float				zoom;
	int					ssaa;
	int					fdf;
	void				*win_ptr;
	t_mouse				mouse;
	t_fractal			fract;
	t_imgx				img;
	t_colors			col;
	pthread_t			thread[D_THREADS];
	t_pthr				limit[D_THREADS];
	t_xvar				*mlx_ptr;
	t_grid				**grid;
}						t_conf;

#endif
