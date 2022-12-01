/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:09:56 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:09:59 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_percent(int current, int start, int end)
{
	int			position;
	int			length;

	position = current - start;
	length = end - start;
	if (!length)
		return (1.0);
	else
		return ((double)position / (double)length);
}

static int		ft_get_gradient(int start, int end, double percent)
{
	double		gradient;

	gradient = (1 - percent) * start + percent * end;
	return ((int)gradient);
}

int				ft_set_gradient(int iteration, int bkmirror, t_conf *conf)
{
	double		percent;
	int			start;
	int			end;
	t_rgb		col;

	percent = ft_percent(iteration, 0, conf->imax - 1);
	if (!bkmirror)
	{
		start = conf->col.colors[conf->col.palette][conf->col.roll];
		end = D_WHITE;
	}
	else
	{
		start = D_BLACK;
		end = conf->col.colors[conf->col.palette][conf->col.roll];
	}
	col.red = ft_get_gradient((start >> 16) & 0xFF, (end >> 16) & 0xFF,
				percent);
	col.green = ft_get_gradient((start >> 8) & 0xFF, (end >> 8) & 0xFF,
				percent);
	col.blue = ft_get_gradient(start & 0xFF, end & 0xFF, percent);
	return ((col.red << 16) | (col.green << 8) | col.blue);
}
