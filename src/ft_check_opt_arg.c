/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_opt_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:03:48 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:03:50 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_check_fract_n(int value, t_conf *conf)
{
	if (value < 1)
		return (D_ERR_FRACTAL_WRONG);
	if (value > 9)
		return (D_ERR_FRACTAL_WRONG);
	if (!conf->fract_number)
		conf->fract_number = value;
	else
		return (D_ERR_FRACTAL_MUCH);
	return (0);
}

static void		ft_set_opt_value(int i, int value, t_conf *conf)
{
	if (i == 4)
		conf->resolution = value;
	else if (i == 5)
		conf->imax = value;
	else if (i == 6)
		conf->level = value;
	else if (i == 7)
		conf->sample = value;
	else if (i == 8)
		conf->imin = value;
	else if (i == 9)
		conf->col.mode = value;
	else if (i == 10)
		conf->col.palette = value;
	else if (i == 11)
		conf->col.roll = value;
	else if (i == 12)
		conf->col.bkg_pal = value;
	else if (i == 13)
		conf->col.bkg_roll = value;
	else if (i == 14)
		conf->ssaa = value;
}

static int		ft_check_opt_limit(int i, t_conf *conf)
{
	if (i == 4 && (conf->resolution <= 0 || conf->resolution > 10000))
		return (D_ERR_OPT_ARG);
	else if (i == 5 && conf->imax <= 0)
		return (D_ERR_OPT_ARG);
	else if (i == 6 && conf->level < 0)
		return (D_ERR_OPT_ARG);
	else if (i == 7 && conf->sample <= 0)
		return (D_ERR_OPT_ARG);
	else if (i == 8 && (conf->imin < 0 || conf->imin >= conf->imax))
		return (D_ERR_OPT_ARG);
	else if (i == 9 && (conf->col.mode < 0 || conf->col.mode > D_MOD_MAX - 1))
		return (D_ERR_OPT_ARG);
	else if (i == 10 && (conf->col.palette < 0
							|| conf->col.palette > D_PAL_MAX - 1))
		return (D_ERR_OPT_ARG);
	else if (i == 11 && (conf->col.roll < 0 || conf->col.roll > D_COL_MAX - 1))
		return (D_ERR_OPT_ARG);
	else if (i == 12 && (conf->col.bkg_pal < 0
							|| conf->col.bkg_pal > D_PAL_MAX - 1))
		return (D_ERR_OPT_ARG);
	else if (i == 13 && (conf->col.bkg_roll < 0 || conf->col.bkg_roll > 4))
		return (D_ERR_OPT_ARG);
	else if (i == 14 && (conf->ssaa <= 0 || conf->ssaa > D_SSAA_MAX))
		return (D_ERR_OPT_ARG);
	return (0);
}

int				ft_check_opt_arg(int i, int j, char *argv, t_conf *conf)
{
	int			value;

	if (!argv)
		return (D_ERR_OPT_ARG);
	while (argv[j])
	{
		if (!ft_isdigit(argv[j++]))
			return (D_ERR_OPT_ARG);
	}
	value = ft_atoi(&argv[0]);
	if (i == 2)
		return (ft_check_fract_n(value, conf));
	ft_set_opt_value(i, value, conf);
	return (ft_check_opt_limit(i, conf));
}
