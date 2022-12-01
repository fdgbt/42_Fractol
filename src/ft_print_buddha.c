/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buddha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:06:27 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:06:29 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_monochrome(t_rgb *col, t_point actual, t_conf *conf)
{
	if (conf->col.mode == 0)
	{
		if (conf->col.roll == 0 || conf->col.roll == 3)
			col->red = conf->fract.buddha[0][actual.y][actual.x]
				* (conf->level + 1);
		else if (conf->col.roll == 1 || conf->col.roll == 4)
			col->green = conf->fract.buddha[0][actual.y][actual.x]
				* (conf->level + 1);
		else if (conf->col.roll == 2 || conf->col.roll == 5)
			col->blue = conf->fract.buddha[0][actual.y][actual.x]
				* (conf->level + 1);
	}
	else if (conf->col.mode == 1)
	{
		col->red = conf->fract.buddha[0][actual.y][actual.x]
			* (conf->level + 1);
		col->green = conf->fract.buddha[0][actual.y][actual.x]
			* (conf->level + 1);
		col->blue = conf->fract.buddha[0][actual.y][actual.x]
			* (conf->level + 1);
	}
}

static void		ft_set_buddha_pix(t_rgb *col, t_point actual, t_conf *conf)
{
	int			pix;

	pix = actual.y * (conf->super_sampling + conf->hud_res) + actual.x;
	if (conf->col.mode < 2)
		ft_print_monochrome(col, actual, conf);
	else
		ft_print_nebula(col, actual, conf);
	if (conf->ssaa > 1)
	{
		conf->grid[actual.x][actual.y].red = col->red;
		conf->grid[actual.x][actual.y].green = col->green;
		conf->grid[actual.x][actual.y].blue = col->blue;
	}
	else
		conf->img.img_data[pix] = (((int)col->red << 16) |
									((int)col->green << 8) | (int)col->blue);
}

void			ft_print_buddha(t_conf *conf)
{
	t_rgb		col;
	t_point		actual;

	col.red = 0;
	col.green = 0;
	col.blue = 0;
	actual.y = 0;
	while (actual.y < conf->super_sampling)
	{
		actual.x = 0;
		while (actual.x < conf->super_sampling)
		{
			ft_set_buddha_pix(&col, actual, conf);
			actual.x++;
		}
		actual.y++;
	}
}
