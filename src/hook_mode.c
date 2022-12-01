/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:12:41 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:12:43 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			hook_fractal(int fractal, t_conf *conf)
{
	conf->fract_number = fractal;
	if (conf->opt[3])
		ft_printf("{BLA}Current fractal: %d.\n{OFF}", conf->fract_number);
	hook_clean_parameter(conf);
}

static void		ft_check_mode(t_conf *conf)
{
	if (conf->fract_number == 5 || !conf->col.mode || conf->col.mode == 4
			|| conf->col.mode == 5)
		conf->col.palette = 20;
	else if (!conf->col.palette || conf->col.palette == 20)
		conf->col.palette = 3;
	conf->col.rgb = 0;
	conf->col.hsv = 0;
	conf->col.bkg = 0;
}

void			hook_mode(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->col.mode++;
	else if (dir == 2)
		conf->col.mode--;
	if (conf->fract_number == 5)
	{
		if (conf->col.mode < 0)
			conf->col.mode = 3;
		else if (conf->col.mode > 3)
			conf->col.mode = 0;
	}
	else if (conf->col.mode < 0)
		conf->col.mode = D_MOD_MAX - 1;
	else if (conf->col.mode > D_MOD_MAX - 1)
		conf->col.mode = 0;
	ft_check_mode(conf);
	if (conf->opt[3])
		ft_printf("{BLA}Current mode: %d\n{OFF}", conf->col.mode);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}

void			hook_check_pal(t_conf *conf)
{
	if (conf->col.palette < 0)
		conf->col.palette = D_PAL_MAX - 1;
	else if (conf->col.palette > D_PAL_MAX - 1)
		conf->col.palette = 0;
}

void			hook_palette(int dir, t_conf *conf)
{
	if (conf->col.mode > 0 && conf->col.mode < 4)
	{
		if (dir == 1)
			conf->col.palette++;
		else if (dir == 2)
			conf->col.palette--;
		hook_check_pal(conf);
	}
	if (conf->opt[3])
		ft_printf("{BLA}Current palette: %d\n{OFF}", conf->col.palette);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}
