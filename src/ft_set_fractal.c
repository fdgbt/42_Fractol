/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:09:44 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:09:45 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_set_pix(int fractal, t_point actual, t_conf *conf)
{
	if (fractal == 1)
		fractal_mandelbrot(0, actual, conf);
	else if (fractal == 2)
		fractal_julia(0, actual, conf);
	else if (fractal == 3)
		fractal_burning_ship(0, actual, conf);
	else if (fractal == 4)
		fractal_multibrot(0, actual, conf);
	else if (fractal == 5)
		fractal_buddhabrot(conf);
	else if (fractal == 6)
		fractal_newton(0, actual, conf);
	else if (fractal == 7)
		fractal_koch(conf);
	else if (fractal == 8)
		fractal_sierpinski(conf);
	else if (fractal == 9)
		fractal_barnsley(conf);
}

static void		ft_set_monothread(int fractal, t_point actual, t_conf *conf)
{
	if (conf->opt[3])
		ft_printf("{BLA}Starting fractal...\n{OFF}");
	while (actual.y < conf->super_sampling)
	{
		actual.x = 0;
		while (actual.x < conf->super_sampling)
		{
			ft_set_pix(fractal, actual, conf);
			actual.x++;
		}
		actual.y++;
	}
}

void			ft_set_fractal(t_conf *conf)
{
	int			fractal;
	t_point		actual;

	fractal = conf->fract_number;
	actual.x = 0;
	actual.y = 0;
	if (fractal == 5 || fractal == 7 || fractal == 8 || fractal == 9)
	{
		hook_clean_screen(conf);
		ft_set_pix(fractal, actual, conf);
	}
	else if (conf->opt[17])
		ft_set_monothread(fractal, actual, conf);
	else
		ft_set_pthr(conf);
	if (conf->ssaa > 1)
		ft_set_ssaa(conf);
	if (conf->opt[3])
		ft_printf("{BLA}Fractal ready !\n{OFF}");
}
