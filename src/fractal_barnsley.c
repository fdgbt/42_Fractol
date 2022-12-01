/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_barnsley.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:01:42 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:01:46 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_calc_barnsley(int random, int *color, t_grid tmp,
									t_grid *actual)
{
	if (random < 1)
	{
		actual->x = 0;
		actual->y *= 0.16;
		*color = 1;
	}
	else if (random < 86)
	{
		actual->x = 0.85 * tmp.x + 0.04 * tmp.y;
		actual->y = -0.04 * tmp.x + 0.85 * tmp.y + 1.6;
		*color = 2;
	}
	else if (random < 93)
	{
		actual->x = 0.2 * tmp.x - 0.26 * tmp.y;
		actual->y = 0.23 * tmp.x + 0.22 * tmp.y + 1.6;
		*color = 3;
	}
	else
	{
		actual->x = -0.15 * tmp.x + 0.28 * tmp.y;
		actual->y = 0.26 * tmp.x + 0.24 * tmp.y + 0.44;
		*color = 4;
	}
}

static void		ft_random_barnsley(int *color, t_grid *actual)
{
	int			random;
	t_grid		tmp;

	tmp.x = actual->x;
	tmp.y = actual->y;
	random = rand() % 101;
	ft_calc_barnsley(random, color, tmp, actual);
}

static void		ft_grid_barnsley(int color, int mid_res, t_grid actual,
									t_conf *conf)
{
	t_grid		tmp;
	t_point		pactual;

	tmp.x = mid_res + (actual.x * mid_res) / conf->fract.xend;
	tmp.y = conf->super_sampling - (actual.y * conf->super_sampling)
				/ conf->fract.yend;
	pactual.x = (int)tmp.x;
	pactual.y = (int)tmp.y;
	if (pactual.x >= 0 && pactual.y >= 0 && pactual.x < conf->super_sampling
			&& pactual.y < conf->super_sampling)
	{
		conf->grid[pactual.x][pactual.y].iteration = color;
		ft_set_img(pactual, conf);
	}
}

void			fractal_barnsley(t_conf *conf)
{
	int			i;
	int			mid_res;
	int			color;
	t_grid		actual;

	srand(time(NULL));
	i = 0;
	mid_res = conf->super_sampling / 2;
	color = 0;
	actual.x = 0;
	actual.y = 0;
	while (i < conf->sample)
	{
		ft_random_barnsley(&color, &actual);
		ft_grid_barnsley(color, mid_res, actual, conf);
		i++;
	}
}
