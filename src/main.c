/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:14:30 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:14:32 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_print_man(void)
{
	int			fd;
	char		*line;

	fd = 0;
	line = NULL;
	if ((fd = open(D_MAN_PATH, O_RDONLY)) < 0)
		return (D_ERR_MAN_OPEN);
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (line[0] == '#')
			ft_printf("{ITAL}{GRE}%s{OFF}\n", line);
		else if (line[0] == '*')
			ft_printf("{UNDER}{BOLD}{CYA}%s{OFF}\n", line);
		else if (line[0] == '-')
			ft_printf("{BOLD}{GRE}%s{OFF}\n", line);
		else
			ft_printf("{GRE}%s{OFF}\n", line);
		free(line);
		line = NULL;
	}
	free(line);
	if (close(fd) < 0)
		return (D_ERR_MAN_CLOSE);
	return (0);
}

static int		ft_print_help(int page)
{
	if (page == 1)
		ft_printf("{GRE}usage: ./fractol mandelbrot\
		\n{YEL}list : ./fractol -l\n{RED}help : ./fractol -h\n{OFF}");
	else if (page == 2)
		return (ft_print_man());
	else if (page == 3)
	{
		ft_printf("{CYA}{BOLD}Fractal list :{OFF}\
		\n{CYA} 1){YEL} ./fractol{GRE} mandelbrot\
		\n{CYA} 2){YEL} ./fractol{GRE} julia\
		\n{CYA} 3){YEL} ./fractol{GRE} burning_ship\
		\n{CYA} 4){YEL} ./fractol{GRE} multibrot\
		\n{CYA} 5){YEL} ./fractol{GRE} buddhabrot\
		\n{CYA} 6){YEL} ./fractol{GRE} newton\
		\n{CYA} 7){YEL} ./fractol{GRE} koch\
		\n{CYA} 8){YEL} ./fractol{GRE} sierpinski\
		\n{CYA} 9){YEL} ./fractol{GRE} barnsley\
		\n{RED}{ITAL}help: ./fractol -h\n{OFF}");
	}
	return (0);
}

static int		ft_init_window(t_conf *conf)
{
	int			err;

	err = 0;
	if (!conf->fract_number)
		return (D_ERR_FRACTAL_MISS);
	if (conf->opt[3])
		ft_printf("{BLA}Starting window...\nFractal: %d, Resolution: %d\
			\nIteration: %d, Sample: %d, Level:%d, Filter: %d\n{OFF}",
			conf->fract_number, conf->resolution, conf->imax, conf->sample,
			conf->level, conf->imin);
	if (!(conf->mlx_ptr = mlx_init()))
		return (D_ERR_MLX_INIT);
	if (!(conf->win_ptr = mlx_new_window(conf->mlx_ptr,
			conf->resolution + conf->hud_res, conf->resolution, "Fract'ol")))
		return (D_ERR_MLX_NEW_WIN);
	if (!(conf->img.img_ptr = mlx_new_image(conf->mlx_ptr,
			conf->resolution + conf->hud_res, conf->resolution)))
		return (D_ERR_MLX_NEW_IMG);
	if (!(conf->img.img_data = (int *)mlx_get_data_addr(conf->img.img_ptr,
			&conf->img.bpp, &conf->img.size_l, &conf->img.endian)))
		return (D_ERR_MLX_GET_DATA);
	if ((err = ft_init_grid(conf)) < 0)
		return (err);
	ft_print_hud(conf);
	return (0);
}

int				main(int argc, char **argv)
{
	int			err;
	t_conf		conf;

	err = 0;
	ft_init_conf(&conf);
	if (argc < 2)
		return (ft_end(ft_print_help(1), &conf));
	else
	{
		if ((err = ft_check_args(0, 1, argv, &conf)) < 0)
			return (ft_end(err, &conf));
		if (conf.opt[0])
			return (ft_end(ft_print_help(2), &conf));
		else if (conf.opt[1])
			return (ft_end(ft_print_help(3), &conf));
		else
		{
			if ((err = ft_init_window(&conf)) < 0)
				return (ft_end(err, &conf));
			if ((err = ft_start_hook(&conf)) < 0)
				return (ft_end(err, &conf));
		}
	}
	return (ft_end(err, &conf));
}
