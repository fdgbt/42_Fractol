/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_parameter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:13:38 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:13:40 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_zoom(int dir, t_conf *conf)
{
	if (dir == 1)
	{
		conf->fract.zoom++;
		conf->zoom *= 1.1;
	}
	else if (dir == 2)
	{
		conf->fract.zoom--;
		conf->zoom *= 0.9;
	}
	if (conf->opt[3])
	{
		ft_printf("{BLA}current Zoom : ");
		ft_print_float("", conf->zoom);
		ft_printf(".\n{OFF}");
	}
	ft_set_grid(conf);
	ft_print_hud(conf);
}

void	hook_iteration(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->imax *= 2;
	else if (dir == 2)
		conf->imax *= 0.5;
	if (conf->imax < 1)
		conf->imax = 1;
	if (conf->opt[3])
		ft_printf("{BLA}Current imax: %d.\n{OFF}", conf->imax);
	ft_set_fractal(conf);
	ft_print_hud(conf);
}

void	hook_level(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->level++;
	else if (dir == 2)
		conf->level--;
	if (conf->level < 0)
		conf->level = 0;
	if (conf->opt[3])
		ft_printf("{BLA}Current level:%d.\n{OFF}", conf->level);
	ft_set_grid(conf);
	ft_print_hud(conf);
}

void	hook_sample(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->sample *= 2;
	else if (dir == 2)
		conf->sample *= 0.5;
	if (conf->sample < 1)
		conf->sample = 1;
	if (conf->opt[3])
		ft_printf("{BLA}Current sample: %d\n{OFF}", conf->sample);
	ft_set_fractal(conf);
	ft_print_hud(conf);
}

void	hook_filter(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->imin += 5;
	else if (dir == 2)
		conf->imin -= 5;
	if (conf->imin < 0)
		conf->imin = 0;
	if (conf->opt[3])
		ft_printf("{BLA}Current filter: %d\n{OFF}", conf->imin);
	ft_set_fractal(conf);
	ft_print_hud(conf);
}
