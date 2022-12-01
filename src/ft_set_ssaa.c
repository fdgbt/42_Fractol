/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ssaa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:11:09 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:11:10 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_sampler(int pix, t_point actual, t_point samp, t_conf *conf)
{
	t_rgb		col;
	int			i;
	int			j;

	col.red = 0;
	col.green = 0;
	col.blue = 0;
	i = 0;
	while (i < conf->ssaa)
	{
		j = 0;
		while (j < conf->ssaa)
		{
			col.red += conf->grid[samp.x + i][samp.y + j].red;
			col.green += conf->grid[samp.x + i][samp.y + j].green;
			col.blue += conf->grid[samp.x + i][samp.y + j].blue;
			j++;
		}
		i++;
	}
	col.red /= conf->ssaa * conf->ssaa;
	col.green /= conf->ssaa * conf->ssaa;
	col.blue /= conf->ssaa * conf->ssaa;
	pix = actual.y * (conf->resolution + conf->hud_res) + actual.x;
	conf->img.img_data[pix] = (col.red << 16) | (col.green << 8) | col.blue;
}

void			ft_set_ssaa(t_conf *conf)
{
	t_point		actual;
	t_point		samp;

	actual.y = 0;
	samp.y = 0;
	if (conf->opt[3])
		ft_printf("{BLA}Starting SSAA...\n{OFF}");
	while (actual.y < conf->resolution)
	{
		actual.x = 0;
		samp.x = 0;
		while (actual.x < conf->resolution)
		{
			ft_sampler(0, actual, samp, conf);
			actual.x++;
			samp.x += conf->ssaa;
		}
		actual.y++;
		samp.y += conf->ssaa;
	}
}

void			hook_ssaa(int dir, t_conf *conf)
{
	if (conf->opt[15])
		conf->ssaa = 1;
	else if (dir == 1)
		conf->ssaa *= 2;
	else
		conf->ssaa /= 2;
	if (!conf->ssaa)
		conf->ssaa = 1;
	if (conf->ssaa > D_SSAA_MAX)
		conf->ssaa = D_SSAA_MAX;
	conf->super_sampling = conf->resolution * conf->ssaa;
	if (conf->opt[15] && conf->opt[3])
		ft_printf("{BLA}SSAA disabled by opt -e (mode eco).\n{OFF}",
			conf->ssaa, conf->super_sampling);
	else if (conf->opt[3])
		ft_printf("{BLA}Current SSAA: %d, sampling: %d.\n{OFF}",
			conf->ssaa, conf->super_sampling);
	ft_set_grid(conf);
	ft_print_hud(conf);
}
