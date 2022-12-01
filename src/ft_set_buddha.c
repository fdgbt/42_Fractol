/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_buddha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:09:02 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:09:04 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_path_buddha(double tmp, int color, t_point actual,
								t_conf *conf)
{
	t_complex	z;
	t_complex	c;
	double		z_x;
	double		z_y;

	z.real = conf->fract.init.real;
	z.imag = conf->fract.init.imag;
	c.real = conf->fract.xstart + actual.x * conf->fract.scale_x;
	c.imag = conf->fract.ystart + actual.y * conf->fract.scale_y;
	while ((z.real * z.real + z.imag * z.imag) < 4)
	{
		tmp = z.real;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * tmp * z.imag + c.imag;
		z_x = (z.real - conf->fract.xstart) / conf->fract.scale_x;
		z_y = (z.imag - conf->fract.ystart) / conf->fract.scale_y;
		if (z_x >= 0 && z_x < conf->super_sampling && z_y >= 0
				&& z_y < conf->super_sampling)
		{
			conf->fract.buddha[color][(int)(z_x)][(int)(z_y)]++;
			conf->grid[(int)(z_x)][(int)(z_y)].iteration++;
		}
	}
}

static void		ft_start_buddha(int i, int color, t_point actual, t_conf *conf)
{
	if (conf->col.mode == 2)
	{
		if (i < conf->imax / 100)
			color = 2;
		else if (i < conf->imax / 10)
			color = 1;
		else
			color = 0;
	}
	ft_path_buddha(0, color, actual, conf);
}

void			ft_set_buddha(int color, t_point actual, t_conf *conf)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.real = conf->fract.init.real;
	z.imag = conf->fract.init.imag;
	c.real = conf->fract.xstart + actual.x * conf->fract.scale_x;
	c.imag = conf->fract.ystart + actual.y * conf->fract.scale_y;
	while ((i < conf->imax) && ((z.real * z.real + z.imag * z.imag) < 4))
	{
		tmp = z.real;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * tmp * z.imag + c.imag;
		i++;
	}
	if (i < conf->imax && i > conf->imin)
		ft_start_buddha(i, color, actual, conf);
}
