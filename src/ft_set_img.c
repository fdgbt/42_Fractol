/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:10:35 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:10:37 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_set_palette(int iteration, int pal, t_conf *conf)
{
	int index;

	index = (iteration + conf->col.roll) % D_COL_MAX;
	if (pal)
		return
		(conf->col.colors[conf->col.palette][index]);
	if (conf->fract_number == 5)
		return (iteration * (conf->level + 1));
	else if (conf->fract_number == 6)
	{
		if (iteration == 0)
			return (D_RED);
		else if (iteration == 1)
			return (D_GREEN);
		else if (iteration == 2)
			return (D_BLUE);
		else
			return (D_BLACK);
	}
	else if (conf->fract_number == 7 || conf->fract_number == 8)
		return (D_WHITE);
	else if (conf->fract_number == 9)
		return (D_GREEN);
	else
		return (conf->col.colors[0][index]);
}

static int		ft_set_rgb(int iteration, t_conf *conf)
{
	int			red;
	int			green;
	int			blue;

	red = (iteration * conf->col.red) % 256;
	green = (iteration * conf->col.green) % 256;
	blue = (iteration * conf->col.blue) % 256;
	return ((red << 16) | (green << 8) | blue);
}

static int		ft_set_mode(int iteration, t_conf *conf)
{
	if (conf->col.mode == 0)
		return (ft_set_palette(iteration, 0, conf));
	else if (conf->col.mode == 1)
		return (ft_set_palette(iteration, 1, conf));
	else if (conf->col.mode == 2)
		return (ft_set_gradient(iteration, 0, conf));
	else if (conf->col.mode == 3)
		return (ft_set_gradient(iteration, 1, conf));
	else if (conf->col.mode == 4)
		return (ft_set_rgb(iteration, conf));
	else if (conf->col.mode == 5)
		return (ft_set_hsv(iteration, conf));
	return (0);
}

static void		ft_set_color_ssaa(int x, int y, t_conf *conf)
{
	if (conf->fract_number < 6 && conf->grid[x][y].iteration == conf->imax)
	{
		conf->grid[x][y].red =
			(conf->col.colors[conf->col.bkg_pal][conf->col.bkg_roll] >> 16)
				& 0xFF;
		conf->grid[x][y].green =
			(conf->col.colors[conf->col.bkg_pal][conf->col.bkg_roll] >> 8)
				& 0xFF;
		conf->grid[x][y].blue =
			conf->col.colors[conf->col.bkg_pal][conf->col.bkg_roll] & 0xFF;
	}
	else
	{
		conf->grid[x][y].red =
			(ft_set_mode(conf->grid[x][y].iteration, conf) >> 16) & 0xFF;
		conf->grid[x][y].green =
			(ft_set_mode(conf->grid[x][y].iteration, conf) >> 8) & 0xFF;
		conf->grid[x][y].blue =
			ft_set_mode(conf->grid[x][y].iteration, conf) & 0xFF;
	}
}

void			ft_set_img(t_point actual, t_conf *conf)
{
	int			pix;

	if (conf->ssaa > 1)
		ft_set_color_ssaa(actual.x, actual.y, conf);
	else
	{
		pix = actual.y * (conf->resolution + conf->hud_res) + actual.x;
		if (conf->fract_number < 6
				&& conf->grid[actual.x][actual.y].iteration == conf->imax)
			conf->img.img_data[pix] =
				conf->col.colors[conf->col.bkg_pal][conf->col.bkg_roll];
		else
			conf->img.img_data[pix] =
				ft_set_mode(conf->grid[actual.x][actual.y].iteration, conf);
	}
}
