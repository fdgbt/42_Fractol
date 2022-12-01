/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sierpinski.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:02:41 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:02:43 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_iter_koch(t_grid segment[2], double angle, int level,
								t_conf *conf)
{
	t_grid		triangle[3];

	triangle[0].x = (2 * segment[0].x + segment[1].x) / 3;
	triangle[0].y = (2 * segment[0].y + segment[1].y) / 3;
	triangle[1].x = (2 * segment[1].x + segment[0].x) / 3;
	triangle[1].y = (2 * segment[1].y + segment[0].y) / 3;
	triangle[2].x = triangle[0].x + (triangle[1].x - triangle[0].x) * cos(angle)
					+ (triangle[1].y - triangle[0].y) * sin(angle);
	triangle[2].y = triangle[0].y + (triangle[1].x - triangle[0].x) *
					-sin(angle) + (triangle[1].y - triangle[0].y) * cos(angle);
	if (level == 0)
		ft_bresenham(level, segment[0], segment[1], conf);
	else
	{
		ft_iter_koch((t_grid[2]){segment[0], triangle[0]}, angle, level - 1,
			conf);
		ft_iter_koch((t_grid[2]){triangle[0], triangle[2]}, angle, level - 1,
			conf);
		ft_iter_koch((t_grid[2]){triangle[2], triangle[1]}, angle, level - 1,
			conf);
		ft_iter_koch((t_grid[2]){triangle[1], segment[1]}, angle, level - 1,
			conf);
	}
}

void			fractal_koch(t_conf *conf)
{
	int			zoom;
	double		angle;
	t_grid		triangle[3];

	zoom = conf->zoom - 2;
	angle = 60 * D_PI / 180;
	triangle[0].x = 200 * conf->ssaa - 50 * zoom * conf->ssaa
					+ conf->fract.offset_x;
	triangle[0].y = 250 * conf->ssaa - 50 * zoom * conf->ssaa
					+ conf->fract.offset_y;
	triangle[1].x = conf->super_sampling - 200 * conf->ssaa + 50 * zoom
					* conf->ssaa + conf->fract.offset_x;
	triangle[1].y = 250 * conf->ssaa - 50 * zoom * conf->ssaa
					+ conf->fract.offset_y;
	triangle[2].x = conf->super_sampling / 2 + conf->fract.offset_x;
	triangle[2].y = conf->super_sampling - 200 * conf->ssaa + 50 * zoom
					* conf->ssaa + conf->fract.offset_y;
	ft_iter_koch((t_grid[2]){triangle[0], triangle[1]}, angle, conf->level,
					conf);
	ft_iter_koch((t_grid[2]){triangle[1], triangle[2]}, angle, conf->level,
					conf);
	ft_iter_koch((t_grid[2]){triangle[2], triangle[0]}, angle, conf->level,
					conf);
}

static t_grid	ft_get_middle(t_grid start, t_grid end)
{
	t_grid		middle;

	middle.x = start.x + (end.x - start.x) / 2;
	middle.y = start.y + (end.y - start.y) / 2;
	return (middle);
}

static void		ft_iter_sierp(t_grid triangle[3], int level, t_conf *conf)
{
	t_grid		middle[3];

	ft_bresenham(level, triangle[0], triangle[1], conf);
	ft_bresenham(level, triangle[1], triangle[2], conf);
	ft_bresenham(level, triangle[2], triangle[0], conf);
	if (level > 0)
	{
		middle[0] = ft_get_middle(triangle[0], triangle[1]);
		middle[1] = ft_get_middle(triangle[1], triangle[2]);
		middle[2] = ft_get_middle(triangle[2], triangle[0]);
		ft_iter_sierp((t_grid[3]){triangle[0], middle[0], middle[2]}, level - 1,
						conf);
		ft_iter_sierp((t_grid[3]){triangle[1], middle[0], middle[1]}, level - 1,
						conf);
		ft_iter_sierp((t_grid[3]){triangle[2], middle[2], middle[1]}, level - 1,
						conf);
	}
}

void			fractal_sierpinski(t_conf *conf)
{
	int			zoom;
	t_grid		triangle[3];

	zoom = conf->zoom - 2;
	triangle[0].x = -50 * zoom * conf->ssaa - conf->fract.offset_x;
	triangle[0].y = conf->super_sampling + 50 * zoom * conf->ssaa
					- conf->fract.offset_y;
	triangle[1].x = conf->super_sampling + 50 * zoom * conf->ssaa
					- conf->fract.offset_x;
	triangle[1].y = conf->super_sampling + 50 * zoom * conf->ssaa
					- conf->fract.offset_y;
	triangle[2].x = conf->super_sampling / 2 - conf->fract.offset_x;
	triangle[2].y = -50 * zoom * conf->ssaa - conf->fract.offset_y;
	ft_iter_sierp(triangle, conf->level, conf);
}
