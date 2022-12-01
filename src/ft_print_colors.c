/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:06:45 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:06:47 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_colors_5(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	if (conf->col.hsv == 2)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1 + 66,
			y, D_MAGENTA, "Sat :");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1 + 66,
			y, D_DEFAULT_GREY_3, "Sat :");
	sprintf(tab, "%d", conf->col.saturation);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	if (conf->col.hsv == 3)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2 + 29,
			y, D_INDIGO, "Value :");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2 + 29,
			y, D_DEFAULT_GREY_3, "Value :");
	sprintf(tab, "%d", conf->col.value);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2 + 80, y,
		D_WHITE, tab);
}

static void		ft_print_colors_4(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	if (conf->col.rgb == 3)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2 + 29,
			y, D_GOOGLE_BLUE, "Blue  :");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2 + 29,
			y, D_DEFAULT_GREY_3, "Blue  :");
	sprintf(tab, "%d", conf->col.blue);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2 + 80, y,
		D_WHITE, tab);
	y += 20;
	if (conf->col.hsv == 1)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
			D_CYAN, "Hue :");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
			D_DEFAULT_GREY_3, "Hue :");
	sprintf(tab, "%d", conf->col.hue);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1 + 38, y,
		D_WHITE, tab);
}

static void		ft_print_colors_3(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	sprintf(tab, "%d", conf->col.bkg_roll);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	y += 20;
	if (conf->col.rgb == 1)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
			D_GOOGLE_RED, "Red :");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
			D_DEFAULT_GREY_3, "Red :");
	sprintf(tab, "%d", conf->col.red);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1 + 38, y,
		D_WHITE, tab);
	if (conf->col.rgb == 2)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1 + 54,
			y, D_GOOGLE_GREEN, "Green :");
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1 + 54,
			y, D_DEFAULT_GREY_3, "Green :");
	sprintf(tab, "%d", conf->col.green);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
}

static void		ft_print_colors_2(int y, int x1, int x2, t_conf *conf)
{
	char		tab[50];

	ft_bzero((void *)tab, 50);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Palette Color  :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, conf->col.palette_name[conf->col.palette]);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Roll Color     :");
	sprintf(tab, "%d", conf->col.roll);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Background Col :");
	sprintf(tab, "%d", conf->col.bkg_pal);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, tab);
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Background Rol :");
}

void			ft_print_colors(int y, int x1, int x2, t_conf *conf)
{
	char tab[50];

	ft_bzero((void *)tab, 50);
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + 133, y,
		D_WHITE, "COLORS");
	y += 50;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Mode Color     :");
	if (conf->fract_number == 5)
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_WHITE, conf->col.mode_buddha[conf->col.mode]);
	else
		mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
			D_WHITE, conf->col.mode_name[conf->col.mode]);
	ft_print_colors_2(y, x1, x2, conf);
	y += 80;
	ft_print_colors_3(y, x1, x2, conf);
	y += 20;
	ft_print_colors_4(y, x1, x2, conf);
	y += 20;
	ft_print_colors_5(y, x1, x2, conf);
}
