/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:08:46 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:08:48 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_params_2(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Filter         :");
	sprintf(tab, "%d", conf->imin);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "SSAA           :");
	sprintf(tab, "%d", conf->ssaa);
	if (conf->opt[15])
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_RED, "Disabled");
	else if (conf->ssaa == 1)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_WHITE, tab);
	else if (conf->ssaa > 1)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GREEN, tab);
}

void			ft_print_params(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + 120, y,
		D_WHITE, "PARAMETERS");
	y += 50;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Iteration      :");
	sprintf(tab, "%d", conf->imax);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Sample         :");
	sprintf(tab, "%d", conf->sample);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Level          :");
	sprintf(tab, "%d", conf->level);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	ft_print_params_2(y, x1, x2, conf);
}
