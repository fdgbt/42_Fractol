/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:05:56 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:05:58 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_press_key_5(int key, t_conf *conf)
{
	if (key == D_KEY_ALTGR)
		hook_set_bkg(conf);
	else if (key == D_KEY_MENU)
		hook_filter(1, conf);
	else if (key == D_KEY_SHIFT_RI)
		hook_filter(2, conf);
}

static void	ft_press_key_4(int key, t_conf *conf)
{
	if (key == D_KEY_SHIFT_LE)
	{
		if (conf->col.bkg)
			hook_bkg(3, conf);
		else
			hook_roll(1, conf);
	}
	else if (key == D_KEY_CTRL_LE)
	{
		if (conf->col.bkg)
			hook_bkg(3, conf);
		else
			hook_roll(2, conf);
	}
	else if (key == D_KEY_ARROW_LE)
		hook_move_axes(1, 0, conf);
	else if (key == D_KEY_ARROW_RI)
		hook_move_axes(2, 0, conf);
	else if (key == D_KEY_ARROW_UP)
		hook_move_axes(3, 0, conf);
	else if (key == D_KEY_ARROW_DO)
		hook_move_axes(4, 0, conf);
	else
		ft_press_key_5(key, conf);
}

static void	ft_press_key_3(int key, t_conf *conf)
{
	if (key == D_KEY_TAB)
	{
		if (conf->col.bkg)
			hook_bkg(1, conf);
		else if (conf->col.mode == 4)
			hook_rgb(1, conf);
		else if (conf->col.mode == 5)
			hook_hsv(1, conf);
		else
			hook_palette(1, conf);
	}
	else if (key == D_KEY_LOCK)
	{
		if (conf->col.bkg)
			hook_bkg(2, conf);
		else if (conf->col.mode == 4)
			hook_rgb(2, conf);
		else if (conf->col.mode == 5)
			hook_hsv(2, conf);
		else
			hook_palette(2, conf);
	}
	else
		ft_press_key_4(key, conf);
}

static void	ft_press_key_2(int key, t_conf *conf)
{
	if (key == D_KEY_BACKSP)
		hook_clean_parameter(conf);
	else if (key == D_KEY_ENTER)
		hook_clean_color(conf);
	else if (key == D_KEY_ESC)
		ft_end(0, conf);
	else if (key == D_KEY_PAGE_UP)
		hook_iteration(1, conf);
	else if (key == D_KEY_PAGE_DO)
		hook_iteration(2, conf);
	else if (key == D_KEY_START)
		hook_sample(1, conf);
	else if (key == D_KEY_END)
		hook_sample(2, conf);
	else if (key == D_KEY_INSER)
		hook_level(1, conf);
	else if (key == D_KEY_DEL)
		hook_level(2, conf);
	else if (key == D_KEY_SPACE)
		hook_mode(1, conf);
	else if (key == D_KEY_ALT)
		hook_mode(2, conf);
	else
		ft_press_key_3(key, conf);
}

int			ft_press_key(int key, t_conf *conf)
{
	if (conf->opt[3])
		ft_printf("{BLA}Key detected: %d.\n{OFF}", key);
	if (key >= D_KEY_A && key <= D_KEY_Z)
		ft_press_key_letter(key, conf);
	if (key == D_KEY_1 || key == D_KEY_NUM_1)
		hook_fractal(1, conf);
	else if (key == D_KEY_2 || key == D_KEY_NUM_2)
		hook_fractal(2, conf);
	else if (key == D_KEY_3 || key == D_KEY_NUM_3)
		hook_fractal(3, conf);
	else if (key == D_KEY_4 || key == D_KEY_NUM_4)
		hook_fractal(4, conf);
	else if (key == D_KEY_5 || key == D_KEY_NUM_5)
		hook_fractal(5, conf);
	else if (key == D_KEY_6 || key == D_KEY_NUM_6)
		hook_fractal(6, conf);
	else if (key == D_KEY_7 || key == D_KEY_NUM_7)
		hook_fractal(7, conf);
	else if (key == D_KEY_8 || key == D_KEY_NUM_8)
		hook_fractal(8, conf);
	else if (key == D_KEY_9 || key == D_KEY_NUM_9)
		hook_fractal(9, conf);
	else
		ft_press_key_2(key, conf);
	return (0);
}
