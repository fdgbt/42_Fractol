/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_newton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:02:26 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:02:29 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	ft_newton_dev(t_complex z)
{
	t_complex		r1;
	t_complex		r2;

	r1.real = 1.0;
	r1.imag = 0;
	r2.real = 2.0;
	r2.imag = 0;
	return (ft_add_c(ft_mult_c(r2, ft_pow_c(z, 3)), r1));
}

static t_complex	ft_newton_deriv(t_complex z)
{
	t_complex		r3;

	r3.real = 3.0;
	r3.imag = 0;
	return (ft_mult_c(r3, ft_mult_c(z, z)));
}

static void			ft_init_root(t_complex root[3])
{
	root[0].real = 1.0;
	root[0].imag = 0;
	root[1].real = -0.5;
	root[1].imag = sqrt(3) / 2;
	root[2].real = -0.5;
	root[2].imag = -sqrt(3) / 2;
}

static int			ft_calc_newton(t_complex z, t_point p, t_point actual,
									t_conf *conf)
{
	int				col;
	float			tolerance;
	t_complex		root[3];
	t_complex		diff;

	col = 0;
	tolerance = 0.001;
	ft_init_root(root);
	diff = ft_sub_c(z, root[p.y]);
	if (ft_dabs(diff.real) < tolerance && ft_dabs(diff.imag) < tolerance)
	{
		conf->grid[actual.x][actual.y].iteration = p.y;
		ft_set_img(actual, conf);
		col++;
	}
	return (col);
}

void				fractal_newton(int col, t_point actual, t_conf *conf)
{
	t_complex		z;
	t_point			p;

	z.real = conf->grid[actual.x][actual.y].x;
	z.imag = conf->grid[actual.x][actual.y].y;
	p.x = 0;
	while (!col && p.x < conf->imax)
	{
		z = ft_div_c(ft_newton_dev(z), ft_newton_deriv(z));
		p.y = 0;
		while (!col && p.y < 3)
		{
			col = ft_calc_newton(z, p, actual, conf);
			p.y++;
		}
		p.x++;
	}
	if (!col)
	{
		conf->grid[actual.x][actual.y].iteration = 3;
		ft_set_img(actual, conf);
	}
}
