/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_buddhabrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:01:57 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:01:59 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_clean_buddha(t_conf *conf)
{
	int			x;
	int			y;
	int			z;

	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < conf->super_sampling)
		{
			z = 0;
			while (z < conf->super_sampling)
			{
				conf->fract.buddha[x][y][z] = 0;
				z++;
			}
			y++;
		}
		x++;
	}
}

static void		*ft_random_axes(t_conf *conf)
{
	int			i;
	int			sample;
	t_point		actual;

	i = 0;
	if (conf->opt[17])
		sample = conf->sample;
	else
		sample = conf->sample / D_THREADS;
	while (i++ < sample)
	{
		actual.x = rand() % conf->super_sampling;
		actual.y = rand() % conf->super_sampling;
		ft_set_buddha(conf->col.color_buddha, actual, conf);
	}
	return (NULL);
}

void			ft_set_pthr_buddha(t_conf *conf)
{
	int		i;

	if (conf->opt[3])
		ft_printf("{BLA}Starting multi-threading...\n{OFF}");
	i = 0;
	while (i < D_THREADS)
	{
		if (pthread_create(&conf->thread[i], NULL,
				(void *)ft_random_axes, conf) != 0)
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

static void		fractal_nebulabrot(t_conf *conf)
{
	conf->imax *= 100;
	while (conf->col.color_buddha < 3)
	{
		if (conf->opt[17])
			ft_random_axes(conf);
		else
			ft_set_pthr_buddha(conf);
		conf->imax /= 10;
		conf->col.color_buddha++;
	}
}

void			fractal_buddhabrot(t_conf *conf)
{
	int imax;

	imax = conf->imax;
	srand(time(NULL));
	ft_clean_buddha(conf);
	conf->col.color_buddha = 0;
	if (conf->col.mode < 3)
	{
		if (conf->opt[17])
			ft_random_axes(conf);
		else
			ft_set_pthr_buddha(conf);
	}
	else
		fractal_nebulabrot(conf);
	ft_print_buddha(conf);
	conf->imax = imax;
}
