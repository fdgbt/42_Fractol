/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_hsv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:12:30 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:12:32 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		hook_check_hsv(t_conf *conf)
{
	if (conf->col.hue < 0)
		conf->col.hue += 360;
	else if (conf->col.hue > 359)
		conf->col.hue -= 360;
	if (conf->col.saturation < 0)
		conf->col.saturation = 100;
	else if (conf->col.saturation > 100)
		conf->col.saturation = 0;
	if (conf->col.value < 0)
		conf->col.value = 100;
	else if (conf->col.value > 100)
		conf->col.value = 0;
}

void		hook_hsv(int dir, t_conf *conf)
{
	if (dir == 1)
	{
		if (conf->col.hsv == 1)
			conf->col.hue++;
		else if (conf->col.hsv == 2)
			conf->col.saturation++;
		else if (conf->col.hsv == 3)
			conf->col.value++;
	}
	else if (dir == 2)
	{
		if (conf->col.hsv == 1)
			conf->col.hue--;
		else if (conf->col.hsv == 2)
			conf->col.saturation--;
		else if (conf->col.hsv == 3)
			conf->col.value--;
	}
	hook_check_hsv(conf);
	if (conf->opt[3])
		ft_printf("{BLA}Current hue: %d, saturation: %d, value: %d\n{OFF}",
					conf->col.hue, conf->col.saturation, conf->col.value);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}

void		hook_set_hsv(int dir, t_conf *conf)
{
	if (conf->col.mode == 5 && conf->col.hsv != dir)
		conf->col.hsv = dir;
	else
		conf->col.hsv = 0;
	if (conf->opt[3])
		ft_printf("{BLA}Current hsv: %d.\n{OFF}", conf->col.hsv);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}
