/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_hsv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:10:25 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:10:27 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_set_hsv_color(t_hsv hsv)
{
	if (hsv.i == 0)
		return (((int)(hsv.v * 255) << 16) | ((int)(hsv.n * 255) << 8)
					| (int)(hsv.l * 255));
	else if (hsv.i == 1)
		return (((int)(hsv.m * 255) << 16) | ((int)(hsv.v * 255) << 8)
					| (int)(hsv.l * 255));
	else if (hsv.i == 2)
		return (((int)(hsv.l * 255) << 16) | ((int)(hsv.v * 255) << 8)
					| (int)(hsv.n * 255));
	else if (hsv.i == 3)
		return (((int)(hsv.l * 255) << 16) | ((int)(hsv.m * 255) << 8)
					| (int)(hsv.v * 255));
	else if (hsv.i == 4)
		return (((int)(hsv.n * 255) << 16) | ((int)(hsv.l * 255) << 8)
					| (int)(hsv.v * 255));
	else if (hsv.i == 5)
		return (((int)(hsv.v * 255) << 16) | ((int)(hsv.l * 255) << 8)
					| (int)(hsv.m * 255));
	else
		return (0);
}

int				ft_set_hsv(int hue, t_conf *conf)
{
	t_hsv		hsv;

	if (conf->fract_number == 6)
		hue *= 60;
	hue = ((hue + conf->col.hue) % 360);
	hsv.s = conf->col.saturation / 100.0;
	hsv.v = conf->col.value / 100.0;
	hsv.h = hue / 60.0;
	hsv.i = floor(hsv.h);
	hsv.f = hsv.h - hsv.i;
	hsv.l = hsv.v * (1.0 - hsv.s);
	hsv.m = hsv.v * (1.0 - hsv.f * hsv.s);
	hsv.n = hsv.v * (1.0 - (1.0 - hsv.f) * hsv.s);
	return (ft_set_hsv_color(hsv));
}
