/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:11:42 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:11:44 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_press_button(int button, int x, int y, t_conf *conf)
{
	conf->mouse.xold = x;
	conf->mouse.yold = y;
	if (conf->fract_number == 5)
	{
		conf->mouse.xold = y;
		conf->mouse.yold = x;
	}
	if (button == D_MOUSE_RIGHT)
		conf->mouse.shift++;
	if (button == D_MOUSE_SCROLL_UP)
		hook_zoom(1, conf);
	else if (button == D_MOUSE_SCROLL_DO)
		hook_zoom(2, conf);
	return (0);
}

static int	ft_release_button(int button, int x, int y, t_conf *conf)
{
	if (conf->opt[3])
		ft_printf("{BLA}Mouse button detected - button:%d, x:%d, y:%d\n{OFF}",
					button, x, y);
	if (button == D_MOUSE_RIGHT)
		conf->mouse.shift = 0;
	return (0);
}

static int	ft_expose(t_conf *conf)
{
	ft_set_img_full(conf);
	ft_print_hud(conf);
	return (0);
}

static int	ft_exit_hook(t_conf *conf)
{
	return (ft_end(0, conf));
}

int			ft_start_hook(t_conf *conf)
{
	if (conf->opt[3])
		ft_printf("{BLA}Starting hook...\n{OFF}");
	mlx_hook(conf->win_ptr, KeyPress, KeyPressMask, ft_press_key, conf);
	mlx_hook(conf->win_ptr, ButtonPress, ButtonPressMask, ft_press_button,
				conf);
	mlx_hook(conf->win_ptr, ButtonRelease, ButtonReleaseMask, ft_release_button,
				conf);
	mlx_hook(conf->win_ptr, MotionNotify, PointerMotionMask, hook_move_mouse,
				conf);
	mlx_hook(conf->win_ptr, FocusIn, FocusChangeMask, ft_expose, conf);
	mlx_hook(conf->win_ptr, D_DESTROY_NOTIFY_NEW, StructureNotifyMask,
				ft_exit_hook, conf);
	if (conf->opt[3])
		ft_printf("{BLA}Starting loop...\n{OFF}");
	mlx_loop(conf->mlx_ptr);
	return (0);
}
