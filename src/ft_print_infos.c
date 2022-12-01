/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:08:06 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:08:10 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_infos_3(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Interval End   :");
	sprintf(tab, "%+f %+fi", conf->fract.xend, conf->fract.yend);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Constant       :");
	sprintf(tab, "%+f %+fi", conf->fract.init.real, conf->fract.init.imag);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
}

static void		ft_print_infos_2(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Multi-Threads  :");
	sprintf(tab, "%d", D_THREADS);
	if (conf->opt[17])
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_RED, "Disabled");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_WHITE, tab);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Zoom           :");
	sprintf(tab, "%f", (float)conf->zoom);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Interval Start :");
	sprintf(tab, "%+f %+fi", conf->fract.xstart, conf->fract.ystart);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
}

void			ft_print_infos(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + 115, y,
		D_WHITE, "INFORMATIONS");
	y += 50;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Fractal        :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, conf->fract_name[conf->fract_number - 1]);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Resolution     :");
	sprintf(tab, "%d x %d", conf->resolution, conf->resolution);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	ft_print_infos_2(y, x1, x2, conf);
	y += 60;
	ft_print_infos_3(y, x1, x2, conf);
}
