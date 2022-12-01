/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:05:42 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:05:44 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_opts(int i, t_conf *conf)
{
	while (i < D_OPT_MAX)
		conf->opt[i++] = 0;
	conf->opt_keys[0] = 'h';
	conf->opt_keys[1] = 'l';
	conf->opt_keys[2] = 'f';
	conf->opt_keys[3] = 'd';
	conf->opt_keys[4] = 'r';
	conf->opt_keys[5] = 'i';
	conf->opt_keys[6] = 'L';
	conf->opt_keys[7] = 's';
	conf->opt_keys[8] = 'I';
	conf->opt_keys[9] = 'm';
	conf->opt_keys[10] = 'p';
	conf->opt_keys[11] = 't';
	conf->opt_keys[12] = 'b';
	conf->opt_keys[13] = 'B';
	conf->opt_keys[14] = 'a';
	conf->opt_keys[15] = 'e';
	conf->opt_keys[16] = 'H';
	conf->opt_keys[17] = 'M';
	conf->opt_keys[18] = 'F';
	conf->opt_keys[19] = 0;
}

static void		ft_init_palette_names(t_conf *conf)
{
	ft_strcpy(conf->col.palette_name[0], "Grey Shade");
	ft_strcpy(conf->col.palette_name[1], "RGB-WB");
	ft_strcpy(conf->col.palette_name[2], "Primary");
	ft_strcpy(conf->col.palette_name[3], "Neutral");
	ft_strcpy(conf->col.palette_name[4], "Pastel");
	ft_strcpy(conf->col.palette_name[5], "Fluo");
	ft_strcpy(conf->col.palette_name[6], "Chill");
	ft_strcpy(conf->col.palette_name[7], "Fire");
	ft_strcpy(conf->col.palette_name[8], "Ocean");
	ft_strcpy(conf->col.palette_name[9], "Snow");
	ft_strcpy(conf->col.palette_name[10], "Camo");
	ft_strcpy(conf->col.palette_name[11], "Safari");
	ft_strcpy(conf->col.palette_name[12], "Fairy");
	ft_strcpy(conf->col.palette_name[13], "Assembly");
	ft_strcpy(conf->col.palette_name[14], "Night City");
	ft_strcpy(conf->col.palette_name[15], "Cyberpunk");
	ft_strcpy(conf->col.palette_name[16], "Spirit");
	ft_strcpy(conf->col.palette_name[17], "Toxic");
	ft_strcpy(conf->col.palette_name[18], "Matrix");
	ft_strcpy(conf->col.palette_name[19], "Google");
	ft_strcpy(conf->col.palette_name[20], "None");
}

void			ft_init_names(t_conf *conf)
{
	conf->fract_number = 0;
	ft_strcpy(conf->fract_name[0], "mandelbrot");
	ft_strcpy(conf->fract_name[1], "julia");
	ft_strcpy(conf->fract_name[2], "burning_ship");
	ft_strcpy(conf->fract_name[3], "multibrot");
	ft_strcpy(conf->fract_name[4], "buddhabrot");
	ft_strcpy(conf->fract_name[5], "newton");
	ft_strcpy(conf->fract_name[6], "koch");
	ft_strcpy(conf->fract_name[7], "sierpinski");
	ft_strcpy(conf->fract_name[8], "barnsley");
	conf->fract_name[9][0] = 0;
	ft_strcpy(conf->col.mode_name[0], "Default");
	ft_strcpy(conf->col.mode_name[1], "Palette");
	ft_strcpy(conf->col.mode_name[2], "Gradient");
	ft_strcpy(conf->col.mode_name[3], "Black Mirror");
	ft_strcpy(conf->col.mode_name[4], "RGB");
	ft_strcpy(conf->col.mode_name[5], "HSV");
	ft_strcpy(conf->col.mode_buddha[0], "Monochrome R/G/B");
	ft_strcpy(conf->col.mode_buddha[1], "Monochrome White");
	ft_strcpy(conf->col.mode_buddha[2], "Radiography");
	ft_strcpy(conf->col.mode_buddha[3], "NASA");
	ft_strcpy(conf->col.mode_buddha[4], "NASA");
	ft_strcpy(conf->col.mode_buddha[5], "NASA");
	ft_init_palette_names(conf);
	ft_init_opts(0, conf);
}
