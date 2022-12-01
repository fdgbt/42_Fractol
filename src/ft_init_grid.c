/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:05:30 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:05:31 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_create_grid(t_conf *conf)
{
	int			x;

	if (!(conf->grid = (t_grid **)malloc(sizeof(*conf->grid)
			* conf->resolution)))
		return (-1);
	x = 0;
	while (x < conf->resolution)
	{
		if (!(conf->grid[x] = (t_grid *)malloc(sizeof(**conf->grid)
				* conf->resolution)))
			return (-1);
		x++;
	}
	return (0);
}

static int		ft_create_ssaa_grid(t_conf *conf)
{
	int			x;
	int			reso_max;

	reso_max = conf->resolution * D_SSAA_MAX;
	if (!(conf->grid = (t_grid **)malloc(sizeof(*conf->grid)
			* reso_max)))
		return (-1);
	x = 0;
	while (x < reso_max)
	{
		if (!(conf->grid[x] = (t_grid *)malloc(sizeof(**conf->grid)
				* reso_max)))
			return (-1);
		x++;
	}
	return (0);
}

static int		ft_create_buddha_grid(t_conf *conf)
{
	int			x;
	int			y;

	if (!(conf->fract.buddha = (int ***)malloc(sizeof(conf->fract.buddha)
			* 3)))
		return (-1);
	x = 0;
	while (x < 3)
	{
		if (!(conf->fract.buddha[x] =
			(int **)malloc(sizeof(*conf->fract.buddha) * conf->resolution)))
			return (-1);
		y = 0;
		while (y < conf->resolution)
		{
			if (!(conf->fract.buddha[x][y] =
				(int *)malloc(sizeof(**conf->fract.buddha) * conf->resolution)))
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

static int		ft_create_ssaa_buddha(t_conf *conf)
{
	int			x;
	int			y;
	int			reso_max;

	reso_max = conf->resolution * D_SSAA_MAX;
	if (!(conf->fract.buddha = (int ***)malloc(sizeof(conf->fract.buddha) * 3)))
		return (-1);
	x = 0;
	while (x < 3)
	{
		if (!(conf->fract.buddha[x] =
			(int **)malloc(sizeof(*conf->fract.buddha) * reso_max)))
			return (-1);
		y = 0;
		while (y < reso_max)
		{
			if (!(conf->fract.buddha[x][y] =
				(int *)malloc(sizeof(**conf->fract.buddha) * reso_max)))
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

int				ft_init_grid(t_conf *conf)
{
	if (conf->opt[3])
		ft_printf("{BLA}Initializing grid...\n{OFF}");
	if (!conf->grid)
	{
		if (conf->opt[15] && ft_create_grid(conf) < 0)
			return (-1);
		else if (!conf->opt[15] && ft_create_ssaa_grid(conf) < 0)
			return (-1);
	}
	if (!conf->fract.buddha)
	{
		if (conf->opt[15] && ft_create_buddha_grid(conf) < 0)
			return (-1);
		else if (!conf->opt[15] && ft_create_ssaa_buddha(conf) < 0)
			return (-1);
	}
	if (!conf->fract.border)
	{
		ft_init_border(conf->fract_number, conf);
		conf->fract.border++;
	}
	ft_set_grid(conf);
	return (0);
}
