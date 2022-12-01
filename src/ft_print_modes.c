/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_modes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:08:20 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:08:23 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_modes_4(int y, int x1, int x2, t_conf *conf)
{
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "HSV Changer    :");
	if (!conf->col.hsv)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_ORANGE, "Inactive");
	else if (conf->col.hsv == 1)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_CYAN, "Hue");
	else if (conf->col.hsv == 2)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_MAGENTA, "Saturation");
	else if (conf->col.hsv == 3)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_INDIGO, "Value");
}

static void		ft_print_modes_3(int y, int x1, int x2, t_conf *conf)
{
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "RGB Changer    :");
	if (!conf->col.rgb)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_ORANGE, "Inactive");
	else if (conf->col.rgb == 1)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_RED, "Red");
	else if (conf->col.rgb == 2)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_GREEN, "Green");
	else if (conf->col.rgb == 3)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_BLUE, "Blue");
}

static void		ft_print_modes_2(int y, int x1, int x2, t_conf *conf)
{
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Epileplic      :");
	if (conf->col.epileptic)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GREEN, "Active");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_ORANGE, "Inactive");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "BKG Changer    :");
	if (conf->col.bkg)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GREEN, "Active");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_ORANGE, "Inactive");
}

void			ft_print_modes(int y, int x1, int x2, t_conf *conf)
{
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + 112, y,
		D_WHITE, "SPECIAL MODES");
	y += 50;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Constant Shift :");
	if (conf->mouse.move_c)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GREEN, "Active");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_ORANGE, "Inactive");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Psychedelic    :");
	if (conf->col.psychedelic)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GREEN, "Active");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_GOOGLE_ORANGE, "Inactive");
	ft_print_modes_2(y, x1, x2, conf);
	y += 40;
	ft_print_modes_3(y, x1, x2, conf);
	y += 20;
	ft_print_modes_4(y, x1, x2, conf);
}
