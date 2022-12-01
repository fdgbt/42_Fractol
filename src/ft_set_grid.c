/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:10:09 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:10:11 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_set_zoom(t_conf *conf)
{
	t_zoom		z;

	if (conf->fract.zoom > 0)
		z.zoom = 0.9;
	else
		z.zoom = 1.1;
	conf->fract.zoom = 0;
	z.x1 = conf->grid[conf->mouse.xold * conf->ssaa][conf->mouse.yold
			* conf->ssaa].x;
	z.deltax = conf->fract.xend - conf->fract.xstart;
	z.dx1 = z.x1 - conf->fract.xstart;
	z.dx2 = z.dx1 * z.zoom;
	conf->fract.xstart = z.x1 - z.dx2;
	conf->fract.xend = conf->fract.xstart + z.deltax * z.zoom;
	z.y1 = conf->grid[conf->mouse.xold * conf->ssaa][conf->mouse.yold
			* conf->ssaa].y;
	z.deltay = conf->fract.yend - conf->fract.ystart;
	z.dy1 = z.y1 - conf->fract.ystart;
	z.dy2 = z.dy1 * z.zoom;
	conf->fract.ystart = z.y1 - z.dy2;
	conf->fract.yend = conf->fract.ystart + z.deltay * z.zoom;
}

static void		ft_set_scale(t_conf *conf)
{
	if (conf->fract.zoom)
		ft_set_zoom(conf);
	conf->fract.scale_x = ft_fabs((conf->fract.xstart - conf->fract.xend)
							/ conf->super_sampling);
	conf->fract.scale_y = ft_fabs((conf->fract.ystart - conf->fract.yend)
							/ conf->super_sampling);
}

static void		ft_set_axes(t_conf *conf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_set_scale(conf);
	while (y < conf->super_sampling)
	{
		x = 0;
		while (x < conf->super_sampling)
		{
			conf->grid[x][y].x = conf->fract.xstart + x * conf->fract.scale_x;
			conf->grid[x][y].y = conf->fract.ystart + y * conf->fract.scale_y;
			conf->grid[x][y].iteration = 0;
			if (conf->ssaa > 1)
			{
				conf->grid[x][y].red = 0;
				conf->grid[x][y].green = 0;
				conf->grid[x][y].blue = 0;
			}
			x++;
		}
		y++;
	}
}

void			ft_set_grid(t_conf *conf)
{
	ft_set_axes(conf);
	ft_set_fractal(conf);
}
