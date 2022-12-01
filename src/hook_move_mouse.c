/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:13:25 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:13:27 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_move_c(int x, int y, t_conf *conf)
{
	if (conf->mouse.xold < x)
		hook_move_c(1, conf);
	else if (conf->mouse.xold > x)
		hook_move_c(2, conf);
	if (conf->mouse.yold < y)
		hook_move_c(3, conf);
	else if (conf->mouse.yold > y)
		hook_move_c(4, conf);
}

static void		ft_move_psy(int x, int y, t_conf *conf)
{
	if (conf->mouse.xold < x)
		hook_psy(1, conf);
	else if (conf->mouse.xold > x)
		hook_psy(2, conf);
	if (conf->mouse.yold < y)
		hook_psy(3, conf);
	else if (conf->mouse.yold > y)
		hook_psy(4, conf);
}

static void		ft_move_axes(int x, int y, t_conf *conf)
{
	if (conf->mouse.xold < x)
		hook_move_axes(1, 1, conf);
	else if (conf->mouse.xold > x)
		hook_move_axes(2, 1, conf);
	if (conf->mouse.yold < y)
		hook_move_axes(3, 1, conf);
	else if (conf->mouse.yold > y)
		hook_move_axes(4, 1, conf);
}

int				hook_move_mouse(int x, int y, t_conf *conf)
{
	if (conf->mouse.move_c)
		ft_move_c(x, y, conf);
	if (conf->col.psychedelic || conf->col.epileptic)
		ft_move_psy(x, y, conf);
	if (conf->mouse.shift)
		ft_move_axes(x, y, conf);
	conf->mouse.xold = x;
	conf->mouse.yold = y;
	return (0);
}
