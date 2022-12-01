/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:02:58 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:03:00 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_bresenham(t_bresenham *bresen, t_grid start, t_grid end)
{
	bresen->x = start.x;
	bresen->y = start.y;
	bresen->dx = ft_abs(end.x - start.x);
	bresen->dy = ft_abs(end.y - start.y);
	if (start.x < end.x)
		bresen->xincr = 1;
	else
		bresen->xincr = -1;
	if (start.y < end.y)
		bresen->yincr = 1;
	else
		bresen->yincr = -1;
	bresen->err = 0;
	bresen->i = 0;
}

static void		ft_go_horizon(int i, t_bresenham *bresen, t_conf *conf)
{
	t_point		actual;

	bresen->err = bresen->dx / 2;
	while (bresen->i < bresen->dx)
	{
		bresen->x += bresen->xincr;
		bresen->err += bresen->dy;
		if (bresen->err > bresen->dx)
		{
			bresen->err -= bresen->dx;
			bresen->y += bresen->yincr;
		}
		actual.x = bresen->x;
		actual.y = bresen->y;
		if (bresen->x >= 0 && bresen->x < conf->super_sampling && bresen->y >= 0
				&& bresen->y < conf->super_sampling)
		{
			conf->grid[actual.x][actual.y].iteration = i;
			ft_set_img(actual, conf);
		}
		bresen->i++;
	}
}

static void		ft_go_vertical(int i, t_bresenham *bresen, t_conf *conf)
{
	t_point		actual;

	bresen->err = bresen->dy / 2;
	while (bresen->i < bresen->dy)
	{
		bresen->y += bresen->yincr;
		bresen->err += bresen->dx;
		if (bresen->err > bresen->dy)
		{
			bresen->err -= bresen->dy;
			bresen->x += bresen->xincr;
		}
		actual.x = bresen->x;
		actual.y = bresen->y;
		if (bresen->x >= 0 && bresen->x < conf->super_sampling && bresen->y >= 0
				&& bresen->y < conf->super_sampling)
		{
			conf->grid[actual.x][actual.y].iteration = i;
			ft_set_img(actual, conf);
		}
		bresen->i++;
	}
}

static void		ft_last_point(int i, t_point start, t_point end, t_conf *conf)
{
	if (start.x >= 0 && start.x < conf->super_sampling && start.y >= 0
			&& start.y < conf->super_sampling)
	{
		conf->grid[start.x][start.y].iteration = i;
		ft_set_img(start, conf);
	}
	if (end.x >= 0 && end.x < conf->super_sampling && end.y >= 0
			&& end.y < conf->super_sampling)
	{
		conf->grid[end.x][end.y].iteration = i;
		ft_set_img(end, conf);
	}
}

void			ft_bresenham(int i, t_grid start, t_grid end, t_conf *conf)
{
	t_bresenham	bresen;
	t_point		pstart;
	t_point		pend;

	pstart.x = (int)start.x;
	pstart.y = (int)start.y;
	pend.x = (int)end.x;
	pend.y = (int)end.y;
	ft_init_bresenham(&bresen, start, end);
	if (bresen.dx > bresen.dy)
		ft_go_horizon(i, &bresen, conf);
	else
		ft_go_vertical(i, &bresen, conf);
	ft_last_point((i + 1) * 10, pstart, pend, conf);
}
