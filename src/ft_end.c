/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:04:00 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:04:02 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_print_error(int nb, char *error)
{
	ft_printf("{BOLD}{UNDER}{RED}ERROR %@%d{OFF}\n", 2, nb);
	ft_printf("{BOLD}{RED}=> %s\n{OFF}", error);
	ft_printf("{ITAL}{RED}list: ./fractol -l\nhelp: ./fractol -h{OFF}\n");
}

static void	ft_init_error_fdf(int error)
{
	char	error_tab[20][50];

	ft_bzero(error_tab[0], 50);
	ft_strcpy(error_tab[1], D_MES_MALLOC);
	ft_strcpy(error_tab[2], D_MES_OPT_KEY);
	ft_strcpy(error_tab[3], D_MES_OPT_ARG);
	ft_strcpy(error_tab[4], D_MES_FRACTAL_WRONG);
	ft_strcpy(error_tab[5], D_MES_FRACTAL_MUCH);
	ft_strcpy(error_tab[6], D_MES_FRACTAL_MISS);
	ft_strcpy(error_tab[7], D_MES_MAN_OPEN);
	ft_strcpy(error_tab[8], D_MES_MAN_CLOSE);
	ft_strcpy(error_tab[9], D_MES_MLX_INIT);
	ft_strcpy(error_tab[10], D_MES_MLX_NEW_WIN);
	ft_strcpy(error_tab[11], D_MES_MLX_NEW_IMG);
	ft_strcpy(error_tab[12], D_MES_MLX_GET_DATA);
	ft_strcpy(error_tab[13], D_MES_THREAD_CREATE);
	ft_strcpy(error_tab[14], D_MES_THREAD_JOIN);
	ft_strcpy(error_tab[15], D_MES_FDF_CREATE);
	ft_strcpy(error_tab[16], D_MES_FDF_CLOSE);
	ft_strcpy(error_tab[17], "RESERVED");
	ft_strcpy(error_tab[18], "RESERVED");
	ft_strcpy(error_tab[19], "RESERVED");
	ft_print_error(error, error_tab[error]);
}

static void	ft_clean_memory(int i, int j, int reso_max, t_conf *conf)
{
	if (conf->opt[15])
		reso_max = conf->resolution;
	else
		reso_max = conf->resolution * D_SSAA_MAX;
	i = 0;
	if (conf->grid)
	{
		while (i < reso_max && conf->grid[i])
			free(conf->grid[i++]);
		free(conf->grid);
	}
	j = 0;
	if (conf->fract.buddha)
	{
		while (j < 3)
		{
			i = 0;
			while (i < reso_max && conf->fract.buddha[j]
					&& conf->fract.buddha[j][i])
				free(conf->fract.buddha[j][i++]);
			free(conf->fract.buddha[j++]);
		}
		free(conf->fract.buddha);
	}
}

static void	ft_clean_mlx(t_conf *conf)
{
	if (conf->mlx_ptr)
	{
		if (conf->img.img_ptr)
			mlx_destroy_image(conf->mlx_ptr, conf->img.img_ptr);
		if (conf->win_ptr)
			mlx_destroy_window(conf->mlx_ptr, conf->win_ptr);
		XCloseDisplay(conf->mlx_ptr->display);
		free(conf->mlx_ptr);
	}
}

int			ft_end(int error, t_conf *conf)
{
	if (error < 0)
		ft_init_error_fdf(-error);
	if (!error && conf->opt[18])
		ft_set_fdf(conf);
	ft_clean_memory(0, 0, 0, conf);
	ft_clean_mlx(conf);
	if (conf->opt[3])
		ft_printf("{BLA}Memory Cleaned ! Exit properly...\n{OFF}");
	exit(error);
}
