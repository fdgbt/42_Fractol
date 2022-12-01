/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_conf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:05:13 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:05:15 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_mouse(t_conf *conf)
{
	conf->mouse.xold = 0;
	conf->mouse.yold = 0;
	conf->mouse.xcount = 0;
	conf->mouse.ycount = 0;
	conf->mouse.move_c = 0;
	conf->mouse.shift = 0;
}

static void		ft_init_fractal(t_conf *conf)
{
	conf->fract.xstart = 0;
	conf->fract.xend = 0;
	conf->fract.ystart = 0;
	conf->fract.yend = 0;
	conf->fract.scale_x = 0;
	conf->fract.scale_y = 0;
	conf->fract.offset_x = 0;
	conf->fract.offset_y = 0;
	conf->fract.border = 0;
	conf->fract.zoom = 0;
	conf->fract.init.real = 0;
	conf->fract.init.imag = 0;
	conf->fract.buddha = NULL;
}

static void		ft_init_mlx(t_conf *conf)
{
	conf->mlx_ptr = NULL;
	conf->win_ptr = NULL;
	conf->img.img_ptr = NULL;
	conf->img.img_data = NULL;
	conf->img.bpp = 0;
	conf->img.size_l = 0;
	conf->img.endian = 0;
}

static void		ft_init_julia(t_conf *conf)
{
	conf->fract.julia_set = 0;
	conf->fract.julia_c[0][0] = -0.8;
	conf->fract.julia_c[0][1] = +0.156;
	conf->fract.julia_c[1][0] = +0.3;
	conf->fract.julia_c[1][1] = +0.5;
	conf->fract.julia_c[2][0] = -0.24;
	conf->fract.julia_c[2][1] = -0.755;
	conf->fract.julia_c[3][0] = -0.4;
	conf->fract.julia_c[3][1] = 0.6;
	conf->fract.julia_c[4][0] = +0.285;
	conf->fract.julia_c[4][1] = +0.01;
	conf->fract.julia_c[5][0] = 0.295;
	conf->fract.julia_c[5][1] = 0;
	conf->fract.julia_c[6][0] = +0.675;
	conf->fract.julia_c[6][1] = -0.39;
	conf->fract.julia_c[7][0] = -1.476;
	conf->fract.julia_c[7][1] = 0;
}

void			ft_init_conf(t_conf *conf)
{
	conf->resolution = D_SCREEN_RES;
	conf->super_sampling = D_SCREEN_RES;
	conf->hud_res = D_HUD_RES;
	conf->imax = D_ITER_MAX;
	conf->imin = D_ITER_MIN;
	conf->hud_cmd = 0;
	conf->level = 0;
	conf->zoom = 1.0;
	conf->sample = 1024 * 1024;
	conf->ssaa = 1;
	conf->fdf = 0;
	conf->grid = NULL;
	ft_init_mlx(conf);
	ft_init_mouse(conf);
	ft_init_fractal(conf);
	ft_init_julia(conf);
	ft_init_names(conf);
	ft_init_colors(conf);
}
