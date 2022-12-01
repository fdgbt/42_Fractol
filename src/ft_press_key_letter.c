/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key_letter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:06:08 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:06:10 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		hook_set_cmd(t_conf *conf)
{
	conf->hud_cmd = !conf->hud_cmd;
	if (conf->opt[3])
		ft_printf("{BLA}Current hud: %d.\n{OFF}", conf->hud_cmd);
	ft_print_hud(conf);
}

static void		ft_press_key_letter_2(int key, t_conf *conf)
{
	if (key == D_KEY_C)
	{
		conf->mouse.move_c = !conf->mouse.move_c;
		ft_print_hud(conf);
	}
	else if (key == D_KEY_J)
		hook_switch_julia(1, conf);
	else if (key == D_KEY_K)
		hook_switch_julia(2, conf);
	else if (key == D_KEY_F)
		hook_set_cmd(conf);
}

void			ft_press_key_letter(int key, t_conf *conf)
{
	if (key == D_KEY_R)
		hook_set_rgb(1, conf);
	else if (key == D_KEY_G)
		hook_set_rgb(2, conf);
	else if (key == D_KEY_B)
		hook_set_rgb(3, conf);
	else if (key == D_KEY_H)
		hook_set_hsv(1, conf);
	else if (key == D_KEY_S)
		hook_set_hsv(2, conf);
	else if (key == D_KEY_V)
		hook_set_hsv(3, conf);
	else if (key == D_KEY_P)
		hook_set_psy(1, conf);
	else if (key == D_KEY_E)
		hook_set_psy(2, conf);
	else if (key == D_KEY_A)
		hook_ssaa(1, conf);
	else if (key == D_KEY_Z)
		hook_ssaa(2, conf);
	else if (key == D_KEY_W)
		ft_set_fdf(conf);
	else
		ft_press_key_letter_2(key, conf);
}
