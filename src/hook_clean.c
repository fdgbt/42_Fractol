/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:12:19 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:12:21 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_print_float(char *text, float value)
{
	float	integer;
	float	decimal;
	int		accuracy;

	accuracy = 1000;
	integer = (int)value;
	decimal = ft_fabs((value - integer) * accuracy);
	ft_printf("%s%d.%-3d", text, (int)integer, (int)decimal);
}

void		ft_set_img_full(t_conf *conf)
{
	t_point	actual;

	if (conf->fract_number == 5 || conf->fract_number > 6)
		ft_set_fractal(conf);
	else
	{
		actual.y = 0;
		while (actual.y < conf->super_sampling)
		{
			actual.x = 0;
			while (actual.x < conf->super_sampling)
			{
				ft_set_img(actual, conf);
				actual.x++;
			}
			actual.y++;
		}
	}
	if (conf->ssaa > 1)
		ft_set_ssaa(conf);
}

void		hook_clean_screen(t_conf *conf)
{
	int		full_res;
	int		i;

	full_res = (conf->resolution + conf->hud_res) * conf->resolution;
	i = 0;
	while (i < full_res)
		conf->img.img_data[i++] = D_BLACK;
}

void		hook_clean_parameter(t_conf *conf)
{
	if (conf->opt[3])
		ft_printf("{BLA}Reset settings...\n{OFF}");
	conf->imax = D_ITER_MAX;
	conf->imin = D_ITER_MIN;
	conf->level = 0;
	conf->sample = 1024 * 1024;
	conf->fract.border = 0;
	conf->fract.zoom = 0;
	conf->fract.julia_set = 0;
	conf->fract.offset_x = 0;
	conf->fract.offset_y = 0;
	conf->zoom = 1.0;
	conf->ssaa = 1;
	conf->super_sampling = conf->resolution;
	conf->mouse.move_c = 0;
	conf->col.rgb = 0;
	conf->col.hsv = 0;
	conf->col.psychedelic = 0;
	conf->col.epileptic = 0;
	hook_clean_screen(conf);
	ft_init_grid(conf);
	ft_print_hud(conf);
}

void		hook_clean_color(t_conf *conf)
{
	if (conf->opt[3])
		ft_printf("{BLA}Reset colors...\n{OFF}");
	conf->col.mode = 0;
	if (!conf->col.mode || conf->col.mode == 4 || conf->col.mode == 5)
		conf->col.palette = 20;
	else
		conf->col.palette = 0;
	conf->col.roll = 0;
	conf->col.bkg = 0;
	conf->col.bkg_pal = 1;
	conf->col.bkg_roll = 0;
	conf->col.rgb = 0;
	conf->col.red = 4;
	conf->col.green = 8;
	conf->col.blue = 16;
	conf->col.hsv = 0;
	conf->col.hue = 0;
	conf->col.saturation = 100;
	conf->col.value = 100;
	conf->col.psychedelic = 0;
	conf->col.epileptic = 0;
	ft_set_fractal(conf);
	ft_print_hud(conf);
}
