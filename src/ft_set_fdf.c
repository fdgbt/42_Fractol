/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:09:33 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:09:35 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char		*ft_get_filename(t_conf *conf)
{
	char	*fractal;
	char	*date;
	char	*filename;
	char	*format;

	fractal = NULL;
	date = NULL;
	filename = NULL;
	format = NULL;
	if (!(fractal = ft_strjoin(conf->fract_name[conf->fract_number - 1], "_")))
		return (NULL);
	date = ft_strnew(16);
	ft_get_date(date);
	if (!(filename = ft_strjoin(fractal, date)))
		return (NULL);
	if (!(format = ft_strjoin(filename, ".fdf")))
		return (NULL);
	free(fractal);
	free(date);
	free(filename);
	return (format);
}

static void		ft_create_fdf(int fd, t_conf *conf)
{
	t_point		actual;

	actual.y = 0;
	while (actual.y < conf->resolution)
	{
		actual.x = 0;
		while (actual.x < conf->resolution)
		{
			ft_printf("%@%d ", fd, conf->grid[actual.x][actual.y].iteration);
			actual.x++;
		}
		ft_printf("%@\n", fd);
		actual.y++;
	}
}

void			ft_set_fdf(t_conf *conf)
{
	int			fd;
	char		*filename;

	if (conf->opt[3])
		ft_printf("{BLA}Starting FdF file...\n{OFF}");
	if (!(filename = ft_get_filename(conf)))
		ft_end(-1, conf);
	if ((fd = open(filename, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU)) <= 0)
	{
		free(filename);
		ft_end(-15, conf);
	}
	free(filename);
	ft_create_fdf(fd, conf);
	if (close(fd) < 0)
		ft_end(-16, conf);
	if (conf->opt[3])
		ft_printf("{BLA}FdF file created !\n{OFF}");
}
