/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_full_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:07:06 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:07:08 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_full_cmd_5(int y, int x1, int x2, t_conf *conf)
{
	y += 40;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Mode Color     :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[SPACE] / [ALT]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Palette Color  :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[TAB]   / [LOCK]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Roll Color     :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[MAJ L] / [CTRL L]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Background Col :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[ALT_GR] then");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "    [TAB]   / [LOCK]");
}

static void		ft_print_full_cmd_4(int y, int x1, int x2, t_conf *conf)
{
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Constant Julia :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[J] / [K]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Constant Shift :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[C]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Psychedelic    :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[P]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Epileptic      :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[E]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Write FdF File :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[W]");
}

static void		ft_print_full_cmd_3(int y, int x1, int x2, t_conf *conf)
{
	y += 40;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Iterations     :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[PAGE UP] / [PAGE DOWN]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Sample         :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[START]   / [END]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Level          :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[INSER]   / [DEL]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Filter         :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[MENU]    / [MAJ RIGHT]");
	y += 40;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "SSAA           :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[A] / [Z]");
}

static void		ft_print_full_cmd_2(int y, int x1, int x2, t_conf *conf)
{
	y += 40;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Change Fractal :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[1] - [9]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Zoom           :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[SCROLL MOUSE]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Move by Mouse  :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[HOLD RIGHT CLIC]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Move X-axis    :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[ARROW LEFT / RIGHT]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Move Y-axis    :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[ARROW UP   / DOWN]");
}

void			ft_print_full_cmd(int y, int x1, int x2, t_conf *conf)
{
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + 111, y,
		D_WHITE, "FULL COMMANDS");
	y += 50;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Quit           :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[ESCAPE]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Reset Params   :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[BACKSPACE]");
	y += 20;
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x1, y,
		D_DEFAULT_GREY_3, "Reset Colors   :");
	mlx_string_put(conf->mlx_ptr, conf->win_ptr, conf->resolution + x2, y,
		D_WHITE, "[ENTER]");
	ft_print_full_cmd_2(y, x1, x2, conf);
	y += 120;
	ft_print_full_cmd_3(y, x1, x2, conf);
	y += 140;
	ft_print_full_cmd_4(y, x1, x2, conf);
	y += 100;
	ft_print_full_cmd_5(y, x1, x2, conf);
	ft_print_full_next(y + 120, x1, x2, conf);
}
