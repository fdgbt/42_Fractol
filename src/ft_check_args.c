/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:03:15 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:03:17 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_check_options(int i, int j, char *argv, t_conf *conf)
{
	if (!argv[1])
		return (D_ERR_OPT_KEY);
	while (conf->opt_keys[i])
	{
		if (argv[j] && argv[j] == conf->opt_keys[i])
		{
			if (!conf->opt[i])
				conf->opt[i] = 1;
			else
				return (D_ERR_OPT_KEY);
			if (i == 2 || (i >= 4 && i <= 14))
			{
				if (!argv[++j])
					return (i);
				else
					return (D_ERR_OPT_ARG);
			}
			else if (!argv[++j])
				return (0);
			else
				i = -1;
		}
		i++;
	}
	return (D_ERR_OPT_KEY);
}

static int		ft_check_fract(char *argv, t_conf *conf)
{
	int			i;

	i = 0;
	if (!conf->fract_number)
	{
		while (conf->fract_name[i][0])
		{
			if (!ft_strcmp(conf->fract_name[i], argv))
			{
				conf->fract_number = i + 1;
				return (0);
			}
			else
				i++;
		}
		return (D_ERR_FRACTAL_WRONG);
	}
	else
		return (D_ERR_FRACTAL_MUCH);
}

int				ft_check_args(int err, int i, char **argv, t_conf *conf)
{
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			if ((err = ft_check_options(0, 1, argv[i], conf)) < 0)
				return (err);
			if (err > 0)
			{
				if ((err = ft_check_opt_arg(err, 0, argv[++i], conf)) < 0)
					return (err);
			}
		}
		else if ((err = ft_check_fract(argv[i], conf)) < 0)
			return (err);
		i++;
	}
	if (conf->opt[15])
		conf->ssaa = 1;
	conf->super_sampling = conf->resolution * conf->ssaa;
	if (conf->opt[16])
		conf->hud_res = 0;
	return (0);
}
