/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_roll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:14:15 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:14:21 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_roll_rgb(int dir, t_conf *conf)
{
	int			tmp;

	tmp = conf->col.red;
	if (dir == 1)
	{
		conf->col.red = conf->col.green;
		conf->col.green = conf->col.blue;
		conf->col.blue = tmp;
	}
	else if (dir == 2)
	{
		conf->col.red = conf->col.blue;
		conf->col.blue = conf->col.green;
		conf->col.green = tmp;
	}
}

static void		ft_roll_hsv(int dir, t_conf *conf)
{
	if (dir == 1)
	{
		if (conf->col.hsv == 1)
			conf->col.hue += 60;
		else if (conf->col.hsv == 2)
			conf->col.saturation += 20;
		else if (conf->col.hsv == 3)
			conf->col.value += 20;
	}
	else if (dir == 2)
	{
		if (conf->col.hsv == 1)
			conf->col.hue -= 60;
		else if (conf->col.hsv == 2)
			conf->col.saturation -= 20;
		else if (conf->col.hsv == 3)
			conf->col.value -= 20;
	}
	hook_check_hsv(conf);
}

void			hook_check_roll(t_conf *conf)
{
	if (conf->col.roll < 0)
		conf->col.roll = D_COL_MAX - 1;
	else if (conf->col.roll > D_COL_MAX - 1)
		conf->col.roll = 0;
}

void			hook_roll(int dir, t_conf *conf)
{
	if (conf->col.mode == 4)
		ft_roll_rgb(dir, conf);
	else if (conf->col.mode == 5)
		ft_roll_hsv(dir, conf);
	else
	{
		if (dir == 1)
			conf->col.roll++;
		else if (dir == 2)
			conf->col.roll--;
		hook_check_roll(conf);
	}
	if (conf->opt[3])
		ft_printf("{BLA}Current roll: %d.\n{OFF}", conf->col.roll);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}
