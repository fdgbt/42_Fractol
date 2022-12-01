/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bkg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:12:08 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:12:10 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		hook_check_bkg(t_conf *conf)
{
	if (conf->col.bkg_pal < 0)
		conf->col.bkg_pal = D_PAL_MAX - 1;
	else if (conf->col.bkg_pal > D_PAL_MAX - 1)
		conf->col.bkg_pal = 0;
	if (conf->col.bkg_roll < 0)
		conf->col.bkg_roll = D_COL_MAX - 1;
	else if (conf->col.bkg_roll > D_COL_MAX - 1)
		conf->col.bkg_roll = 0;
}

void		hook_bkg(int dir, t_conf *conf)
{
	if (dir == 1)
		conf->col.bkg_pal++;
	else if (dir == 2)
		conf->col.bkg_pal--;
	else if (dir == 3)
		conf->col.bkg_roll++;
	else if (dir == 4)
		conf->col.bkg_roll--;
	hook_check_bkg(conf);
	if (conf->opt[3])
		ft_printf("{BLA}Current background palette: %d - roll : %d\n{OFF}",
			conf->col.bkg_pal, conf->col.bkg_roll);
	ft_set_img_full(conf);
	ft_print_hud(conf);
}

void		hook_set_bkg(t_conf *conf)
{
	if (!conf->col.bkg)
		conf->col.bkg = 1;
	else
		conf->col.bkg = 0;
	if (conf->opt[3])
	{
		if (!conf->col.bkg)
			ft_printf("{BLA}Principal color mode enabled.\n{OFF}");
		else
			ft_printf("{BLA}Background color mode enabled.\n{OFF}");
	}
	ft_set_img_full(conf);
	ft_print_hud(conf);
}
