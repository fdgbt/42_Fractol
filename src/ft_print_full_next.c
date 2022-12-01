/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_full_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:07:33 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:07:36 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_full_n2(int y, int x1, int x2, t_conf *conf)
{
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Hue (HSV Mode) :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[H]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Saturat. (HSV) :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[S]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Value (HSV)    :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[V]");
	y += 40;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Fractal Infos  :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[F]");
}

void			ft_print_full_next(int y, int x1, int x2, t_conf *conf)
{
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Background Rol :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[ALT_GR] then");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "    [MAJ L] / [CTRL L]");
	y += 40;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Red (RGB Mode) :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[R]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Green (RGB)    :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[G]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Blue (RGB)     :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[B]");
	ft_print_full_n2(y, x1, x2, conf);
}
