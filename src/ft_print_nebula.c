/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nebula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:08:32 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:08:35 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_roll(t_rgb roll, t_rgb *col, t_point actual,
								t_conf *conf)
{
	col->red = conf->fract.buddha[roll.red][actual.y][actual.x]
		* (conf->level + 1);
	col->green = conf->fract.buddha[roll.green][actual.y][actual.x]
		* (conf->level + 1);
	col->blue = conf->fract.buddha[roll.blue][actual.y][actual.x]
		* (conf->level + 1);
}

static void		ft_print_nebula_2(t_rgb *col, t_point actual, t_conf *conf)
{
	t_rgb		roll;

	if (conf->col.roll == 3)
	{
		roll.red = 1;
		roll.green = 0;
		roll.blue = 2;
		ft_print_roll(roll, col, actual, conf);
	}
	else if (conf->col.roll == 4)
	{
		roll.red = 0;
		roll.green = 2;
		roll.blue = 1;
		ft_print_roll(roll, col, actual, conf);
	}
}

void			ft_print_nebula(t_rgb *col, t_point actual, t_conf *conf)
{
	t_rgb		roll;

	if (conf->col.roll == 0)
	{
		roll.red = 0;
		roll.green = 1;
		roll.blue = 2;
		ft_print_roll(roll, col, actual, conf);
	}
	else if (conf->col.roll == 1)
	{
		roll.red = 1;
		roll.green = 2;
		roll.blue = 0;
		ft_print_roll(roll, col, actual, conf);
	}
	else if (conf->col.roll == 2)
	{
		roll.red = 2;
		roll.green = 1;
		roll.blue = 0;
		ft_print_roll(roll, col, actual, conf);
	}
	else
		ft_print_nebula_2(col, actual, conf);
}
