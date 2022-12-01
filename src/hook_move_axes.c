/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_axes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:12:55 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:12:56 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_move_buddha(int dir, double offset_x, double offset_y,
								t_conf *conf)
{
	if (dir == 1)
	{
		conf->fract.ystart -= offset_y;
		conf->fract.yend -= offset_y;
	}
	else if (dir == 2)
	{
		conf->fract.ystart += offset_y;
		conf->fract.yend += offset_y;
	}
	else if (dir == 3)
	{
		conf->fract.xstart -= offset_x;
		conf->fract.xend -= offset_x;
	}
	else if (dir == 4)
	{
		conf->fract.xstart += offset_x;
		conf->fract.xend += offset_x;
	}
}

static void		ft_move_koch_sierp(int dir, double offset_x, double offset_y,
									t_conf *conf)
{
	if (conf->fract_number == 7)
	{
		if (dir == 1)
			conf->fract.offset_x += offset_x;
		else if (dir == 2)
			conf->fract.offset_x -= offset_x;
		else if (dir == 3)
			conf->fract.offset_y += offset_y;
		else if (dir == 4)
			conf->fract.offset_y -= offset_x;
	}
	else
	{
		if (dir == 1)
			conf->fract.offset_x -= offset_x;
		else if (dir == 2)
			conf->fract.offset_x += offset_x;
		else if (dir == 3)
			conf->fract.offset_y -= offset_y;
		else if (dir == 4)
			conf->fract.offset_y += offset_x;
	}
}

static void		ft_move_graphic(int dir, int mouse, t_conf *conf)
{
	double offset_x;
	double offset_y;

	offset_x = 10;
	offset_y = 10;
	if (mouse)
	{
		offset_x = 1;
		offset_y = 1;
	}
	ft_move_koch_sierp(dir, offset_x, offset_y, conf);
}

static void		ft_move_fractal(int dir, double offset_x, double offset_y,
								t_conf *conf)
{
	if (dir == 1)
	{
		conf->fract.xstart -= offset_x;
		conf->fract.xend -= offset_x;
	}
	else if (dir == 2)
	{
		conf->fract.xstart += offset_x;
		conf->fract.xend += offset_x;
	}
	else if (dir == 3)
	{
		conf->fract.ystart -= offset_y;
		conf->fract.yend -= offset_y;
	}
	else if (dir == 4)
	{
		conf->fract.ystart += offset_y;
		conf->fract.yend += offset_y;
	}
}

void			hook_move_axes(int dir, int mouse, t_conf *conf)
{
	double offset_x;
	double offset_y;

	offset_x = conf->fract.scale_x;
	offset_y = conf->fract.scale_y;
	if (!mouse)
	{
		offset_x *= 20;
		offset_y *= 20;
	}
	if (conf->fract_number == 5)
		ft_move_buddha(dir, offset_x, offset_y, conf);
	else if (conf->fract_number == 7 || conf->fract_number == 8)
		ft_move_graphic(dir, mouse, conf);
	else
		ft_move_fractal(dir, offset_x, offset_y, conf);
	if (conf->opt[3])
	{
		ft_printf("{BLA}Current move - ");
		ft_print_float("x: ", conf->fract.xstart);
		ft_print_float(" - y: ", conf->fract.ystart);
		ft_printf(".\n{OFF}");
	}
	ft_set_grid(conf);
	ft_print_hud(conf);
}
