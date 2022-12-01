/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:04:30 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:04:33 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_border_2(int i, t_conf *conf)
{
	if (i == 3 || i == 4 || i == 6)
	{
		conf->fract.xstart = -2;
		conf->fract.xend = 2;
		conf->fract.ystart = -2;
		conf->fract.yend = 2;
		if (i == 4 && !conf->opt[6])
			conf->level = 3;
	}
	else if (i == 7 || i == 8)
	{
		conf->fract.xstart = 0;
		conf->fract.xend = conf->super_sampling;
		conf->fract.ystart = 0;
		conf->fract.yend = conf->super_sampling;
	}
	else if (i == 9)
	{
		conf->fract.xstart = -3;
		conf->fract.xend = 3;
		conf->fract.ystart = 0;
		conf->fract.yend = 10;
	}
}

void			ft_init_border(int i, t_conf *conf)
{
	conf->fract.init.real = 0;
	conf->fract.init.imag = 0;
	if (i == 1 || i == 5)
	{
		conf->fract.xstart = -2;
		conf->fract.xend = 0.7;
		conf->fract.ystart = -1.2;
		conf->fract.yend = 1.2;
		if (i == 5 && !conf->opt[6])
			conf->level = 5;
	}
	else if (i == 2)
	{
		conf->fract.xstart = -1.7;
		conf->fract.xend = 1.7;
		conf->fract.ystart = -1.7;
		conf->fract.yend = 1.7;
		conf->fract.init.real = conf->fract.julia_c[conf->fract.julia_set][0];
		conf->fract.init.imag = conf->fract.julia_c[conf->fract.julia_set][1];
	}
	else
		ft_init_border_2(i, conf);
	if (conf->opt[6])
		conf->opt[6] = 0;
}
