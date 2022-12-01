/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_multibrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:02:13 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:02:16 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fractal_mandelbrot(int i, t_point actual, t_conf *conf)
{
	t_complex	z;
	t_complex	c;
	double		tmp;

	z.real = conf->fract.init.real;
	z.imag = conf->fract.init.imag;
	c.real = conf->grid[actual.x][actual.y].x;
	c.imag = conf->grid[actual.x][actual.y].y;
	while ((i < conf->imax) && ((z.real * z.real + z.imag * z.imag) < 4))
	{
		tmp = z.real;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * tmp * z.imag + c.imag;
		i++;
	}
	conf->grid[actual.x][actual.y].iteration = i;
	ft_set_img(actual, conf);
}

void			fractal_julia(int i, t_point actual, t_conf *conf)
{
	t_complex	z;
	t_complex	c;
	double		tmp;

	c.real = conf->fract.init.real;
	c.imag = conf->fract.init.imag;
	z.real = conf->grid[actual.x][actual.y].x;
	z.imag = conf->grid[actual.x][actual.y].y;
	while ((i < conf->imax) && ((z.real * z.real + z.imag * z.imag) < 4))
	{
		tmp = z.real;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * tmp * z.imag + c.imag;
		i++;
	}
	conf->grid[actual.x][actual.y].iteration = i;
	ft_set_img(actual, conf);
}

void			fractal_burning_ship(int i, t_point actual, t_conf *conf)
{
	t_complex	z;
	t_complex	c;
	double		tmp;

	z.real = conf->fract.init.real;
	z.imag = conf->fract.init.imag;
	c.real = conf->grid[actual.x][actual.y].x;
	c.imag = conf->grid[actual.x][actual.y].y;
	while ((i < conf->imax) && ((z.real * z.real + z.imag * z.imag) < 4))
	{
		z.real = ft_dabs(z.real);
		z.imag = ft_dabs(z.imag);
		tmp = z.real;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * tmp * z.imag + c.imag;
		i++;
	}
	conf->grid[actual.x][actual.y].iteration = i;
	ft_set_img(actual, conf);
}

void			fractal_multibrot(int i, t_point actual, t_conf *conf)
{
	t_complex	z;
	t_complex	c;
	double		tmp;

	z.real = conf->fract.init.real;
	z.imag = conf->fract.init.imag;
	c.real = conf->grid[actual.x][actual.y].x;
	c.imag = conf->grid[actual.x][actual.y].y;
	while ((i < conf->imax) && ((z.real * z.real + z.imag * z.imag) < 4))
	{
		tmp = pow((z.real * z.real + z.imag * z.imag), (conf->level / 2))
				* cos(conf->level * atan2(z.imag, z.real)) + c.real;
		z.imag = pow((z.real * z.real + z.imag * z.imag), (conf->level / 2))
				* sin(conf->level * atan2(z.imag, z.real)) + c.imag;
		z.real = tmp;
		i++;
	}
	conf->grid[actual.x][actual.y].iteration = i;
	ft_set_img(actual, conf);
}
