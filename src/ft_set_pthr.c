/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pthr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:10:53 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:10:55 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			ft_get_thread_index(t_conf *conf)
{
	int			i;
	pthread_t	actual_thread;

	i = 0;
	actual_thread = pthread_self();
	while (i < D_THREADS)
	{
		if (actual_thread == conf->thread[i])
			return (i);
		i++;
	}
	return (-1);
}

static void			ft_set_pix_thread(int fractal, t_point actual, t_conf *conf)
{
	if (fractal == 1)
		fractal_mandelbrot(0, actual, conf);
	else if (fractal == 2)
		fractal_julia(0, actual, conf);
	else if (fractal == 3)
		fractal_burning_ship(0, actual, conf);
	else if (fractal == 4)
		fractal_multibrot(0, actual, conf);
	else if (fractal == 6)
		fractal_newton(0, actual, conf);
}

static void			*ft_set_thread(t_conf *conf)
{
	int				actual_thread;
	t_point			actual_pos;

	actual_thread = ft_get_thread_index(conf);
	if (actual_thread < 0)
		return ((void *)1);
	actual_pos.y = conf->limit[actual_thread].start;
	while (actual_pos.y < conf->limit[actual_thread].end)
	{
		actual_pos.x = 0;
		while (actual_pos.x < conf->super_sampling)
		{
			ft_set_pix_thread(conf->fract_number, actual_pos, conf);
			actual_pos.x++;
		}
		actual_pos.y++;
	}
	return (NULL);
}

void				ft_set_pthr(t_conf *conf)
{
	int		i;

	if (conf->opt[3])
		ft_printf("{BLA}Starting multi-threading...\n{OFF}");
	i = 0;
	while (i < D_THREADS)
	{
		conf->limit[i].start = (conf->super_sampling / D_THREADS) * i;
		conf->limit[i].end = (conf->super_sampling / D_THREADS) * (i + 1);
		if (pthread_create(&conf->thread[i], NULL, (void *)ft_set_thread, conf)
				!= 0)
			ft_end(-13, conf);
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (pthread_join(conf->thread[i], NULL) != 0)
			ft_end(-14, conf);
		i--;
	}
}
