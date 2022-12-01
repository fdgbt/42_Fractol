/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_psy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:13:50 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:13:52 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_epi_rgb(t_conf *conf)
{
	int			tmp;

	tmp = conf->col.red;
	if (conf->mouse.xcount > D_MOUSE_SENSI)
	{
		conf->col.red = conf->col.green;
		conf->col.green = conf->col.blue;
		conf->col.blue = tmp;
	}
	else if (conf->mouse.xcount < -D_MOUSE_SENSI)
	{
		conf->col.red = conf->col.blue;
		conf->col.blue = conf->col.green;
		conf->col.green = tmp;
	}
}

static void		ft_psy_rgb(t_conf *conf)
{
	if (conf->col.mode == 4)
	{
		if (conf->col.psychedelic)
		{
			if (conf->mouse.xcount > D_MOUSE_SENSI)
				conf->col.red++;
			else if (conf->mouse.xcount < -D_MOUSE_SENSI)
				conf->col.red--;
			else if (conf->mouse.ycount > D_MOUSE_SENSI)
				conf->col.green++;
			else if (conf->mouse.ycount < -D_MOUSE_SENSI)
				conf->col.green--;
		}
		if (conf->col.epileptic)
			ft_epi_rgb(conf);
	}
}

static void		ft_psy_hsv_pal(t_conf *conf)
{
	if (conf->col.mode == 5)
	{
		if (conf->col.psychedelic && conf->mouse.xcount > D_MOUSE_SENSI)
			conf->col.hue++;
		else if (conf->col.psychedelic && conf->mouse.xcount < -D_MOUSE_SENSI)
			conf->col.hue--;
		else if (conf->col.epileptic && conf->mouse.ycount > D_MOUSE_SENSI)
			conf->col.hue += 60;
		else if (conf->col.epileptic && conf->mouse.ycount < -D_MOUSE_SENSI)
			conf->col.hue -= 60;
	}
	else
	{
		if (conf->col.epileptic && conf->mouse.xcount > D_MOUSE_SENSI)
			conf->col.palette++;
		else if (conf->col.epileptic && conf->mouse.xcount < -D_MOUSE_SENSI)
			conf->col.palette--;
		else if (conf->col.psychedelic && conf->mouse.ycount > D_MOUSE_SENSI)
			conf->col.roll++;
		else if (conf->col.psychedelic && conf->mouse.ycount < -D_MOUSE_SENSI)
			conf->col.roll--;
		if (conf->col.epileptic && conf->col.psychedelic)
			conf->col.bkg_pal++;
	}
}

void			hook_psy(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->mouse.xcount--;
	else if (dir == 2)
		conf->mouse.xcount++;
	else if (dir == 3)
		conf->mouse.ycount--;
	else if (dir == 4)
		conf->mouse.ycount++;
	ft_psy_rgb(conf);
	ft_psy_hsv_pal(conf);
	hook_check_rgb(conf);
	hook_check_hsv(conf);
	hook_check_pal(conf);
	hook_check_roll(conf);
	hook_check_bkg(conf);
	if (conf->mouse.xcount > D_MOUSE_SENSI
		|| conf->mouse.xcount < -D_MOUSE_SENSI
		|| conf->mouse.ycount > D_MOUSE_SENSI
		|| conf->mouse.ycount < -D_MOUSE_SENSI)
	{
		conf->mouse.xcount = 0;
		conf->mouse.ycount = 0;
		ft_set_img_full(conf);
		ft_print_hud(conf);
	}
}

void			hook_set_psy(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->col.psychedelic = !conf->col.psychedelic;
	else if (dir == 2)
		conf->col.epileptic = !conf->col.epileptic;
	if (conf->opt[3])
		ft_printf("{BLA}Current psychedelic: %d, epileptic: %d.\n{OFF}",
					conf->col.psychedelic, conf->col.epileptic);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}
