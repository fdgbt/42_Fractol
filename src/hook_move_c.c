/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:13:12 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:13:14 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			hook_switch_julia(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->fract.julia_set++;
	else if (dir == 2)
		conf->fract.julia_set--;
	if (conf->fract.julia_set < 0)
		conf->fract.julia_set = D_JULIA_MAX - 1;
	else if (conf->fract.julia_set > D_JULIA_MAX - 1)
		conf->fract.julia_set = 0;
	conf->fract.border = 0;
	if (conf->opt[3])
	{
		ft_printf("{BLA}Current julia: %d.\n{OFF}", conf->fract.julia_set);
		ft_print_float("Current c0 real: ",
			conf->fract.julia_c[conf->fract.julia_set][0]);
		ft_print_float(", imag: ",
			conf->fract.julia_c[conf->fract.julia_set][1]);
		ft_printf(".\n{OFF}");
	}
	ft_init_grid(conf);
	ft_print_hud(conf);
}

static void		ft_mouse_c(t_conf *conf)
{
	if (conf->mouse.xcount > D_MOUSE_SENSI / 2
		|| conf->mouse.xcount < -D_MOUSE_SENSI / 2
		|| conf->mouse.ycount > D_MOUSE_SENSI / 2
		|| conf->mouse.ycount < -D_MOUSE_SENSI / 2)
	{
		if (conf->opt[3])
		{
			ft_printf("{BLA}Current move - ");
			ft_print_float("real: ", conf->fract.init.real);
			ft_print_float(" - imag: ", conf->fract.init.imag);
			ft_printf(".\n{OFF}");
		}
		conf->mouse.xcount = 0;
		conf->mouse.ycount = 0;
		ft_set_fractal(conf);
		ft_print_hud(conf);
	}
}

void			hook_move_c(int dir, t_conf *conf)
{
	double offset_x;
	double offset_y;

	offset_x = 0.005;
	offset_y = 0.01;
	if (dir == 1)
		conf->mouse.xcount--;
	else if (dir == 2)
		conf->mouse.xcount++;
	else if (dir == 3)
		conf->mouse.ycount--;
	else if (dir == 4)
		conf->mouse.ycount++;
	if (conf->mouse.xcount < -D_MOUSE_SENSI / 2)
		conf->fract.init.real -= offset_x;
	else if (conf->mouse.xcount > D_MOUSE_SENSI / 2)
		conf->fract.init.real += offset_x;
	else if (conf->mouse.ycount < -D_MOUSE_SENSI / 2)
		conf->fract.init.imag -= offset_y;
	else if (conf->mouse.ycount > D_MOUSE_SENSI / 2)
		conf->fract.init.imag += offset_y;
	ft_mouse_c(conf);
}
