/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:07:46 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:07:49 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_set_background(int y, int set, t_conf *conf)
{
	int			xres;
	int			ymax;
	int			x;
	int			pix;

	xres = conf->resolution + conf->hud_res;
	ymax = y + 32;
	while (y < ymax)
	{
		x = conf->resolution;
		while (x < xres)
		{
			pix = y * xres + x;
			if (!set)
				conf->img.img_data[pix] = D_BKG_MENU;
			else
				conf->img.img_data[pix] = D_BLACK;
			x++;
		}
		y++;
	}
}

static void		ft_print_cmd(int y, int x1, int x2, t_conf *conf)
{
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + 127, y,
		D_WHITE, "COMMANDS");
	y += 50;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Quit           :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[ESCAPE]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Change Fractal :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[1] - [9]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Full Commands  :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[F]");
}

static void		ft_hud_default(t_conf *conf)
{
	if (conf->resolution >= 30)
		ft_set_background(0, 0, conf);
	if (conf->resolution >= 260)
		ft_set_background(220, 0, conf);
	if (conf->resolution >= 440)
		ft_set_background(400, 0, conf);
	if (conf->resolution >= 665)
		ft_set_background(625, 0, conf);
	if (conf->resolution >= 860)
		ft_set_background(825, 0, conf);
	mlx_put_image_to_window(conf->mlx_ptr, conf->win_ptr, conf->img.img_ptr,
		0, 0);
	ft_print_infos(20, 50, 155, conf);
	ft_print_params(240, 50, 155, conf);
	ft_print_colors(420, 50, 155, conf);
	ft_print_modes(645, 50, 155, conf);
	ft_print_cmd(845, 50, 155, conf);
}

static void		ft_hud_cmd(t_conf *conf)
{
	if (conf->resolution >= 260)
		ft_set_background(220, 1, conf);
	if (conf->resolution >= 440)
		ft_set_background(400, 1, conf);
	if (conf->resolution >= 665)
		ft_set_background(625, 1, conf);
	if (conf->resolution >= 860)
		ft_set_background(825, 1, conf);
	mlx_put_image_to_window(conf->mlx_ptr, conf->win_ptr, conf->img.img_ptr,
		0, 0);
	ft_print_full_cmd(20, 50, 155, conf);
}

void			ft_print_hud(t_conf *conf)
{
	if (!conf->opt[16])
	{
		if (!conf->hud_cmd)
			ft_hud_default(conf);
		else
			ft_hud_cmd(conf);
	}
	else
		mlx_put_image_to_window(conf->mlx_ptr, conf->win_ptr, conf->img.img_ptr,
			0, 0);
}
