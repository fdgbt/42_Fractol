/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:14:01 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:14:02 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		hook_check_rgb(t_conf *conf)
{
	if (conf->col.red < 0)
		conf->col.red = 0;
	else if (conf->col.red > 100)
		conf->col.red = 100;
	if (conf->col.green < 0)
		conf->col.green = 0;
	else if (conf->col.green > 100)
		conf->col.green = 100;
	if (conf->col.blue < 0)
		conf->col.blue = 0;
	else if (conf->col.blue > 100)
		conf->col.blue = 100;
}

void		hook_rgb(int dir, t_conf *conf)
{
	if (dir == 1)
	{
		if (conf->col.rgb == 1)
			conf->col.red++;
		else if (conf->col.rgb == 2)
			conf->col.green++;
		else if (conf->col.rgb == 3)
			conf->col.blue++;
	}
	else if (dir == 2)
	{
		if (conf->col.rgb == 1)
			conf->col.red--;
		else if (conf->col.rgb == 2)
			conf->col.green--;
		else if (conf->col.rgb == 3)
			conf->col.blue--;
	}
	hook_check_rgb(conf);
	if (conf->opt[3])
		ft_printf("{BLA}Current red: %d, green: %d, blue: %d\n{OFF}",
			conf->col.red, conf->col.green, conf->col.blue);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}

void		hook_set_rgb(int dir, t_conf *conf)
{
	if (conf->col.mode == 4 && conf->col.rgb != dir)
		conf->col.rgb = dir;
	else
		conf->col.rgb = 0;
	if (conf->opt[3])
		ft_printf("{BLA}Current rgb: %d.\n{OFF}", conf->col.rgb);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}
