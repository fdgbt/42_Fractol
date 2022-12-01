/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:04:44 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:04:47 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_palettes_1(t_conf *conf)
{
	conf->col.colors[0][0] = D_DEFAULT_GREY_1;
	conf->col.colors[0][1] = D_DEFAULT_GREY_2;
	conf->col.colors[0][2] = D_DEFAULT_GREY_3;
	conf->col.colors[0][3] = D_DEFAULT_GREY_4;
	conf->col.colors[0][4] = D_DEFAULT_GREY_5;
	conf->col.colors[1][0] = D_BLACK;
	conf->col.colors[1][1] = D_WHITE;
	conf->col.colors[1][2] = D_RED;
	conf->col.colors[1][3] = D_GREEN;
	conf->col.colors[1][4] = D_BLUE;
	conf->col.colors[2][0] = D_GREY;
	conf->col.colors[2][1] = D_INDIGO;
	conf->col.colors[2][2] = D_YELLOW;
	conf->col.colors[2][3] = D_MAGENTA;
	conf->col.colors[2][4] = D_CYAN;
	conf->col.colors[3][0] = D_NEUTRAL_RED;
	conf->col.colors[3][1] = D_NEUTRAL_GREEN;
	conf->col.colors[3][2] = D_NEUTRAL_BLUE;
	conf->col.colors[3][3] = D_NEUTRAL_YELLOW;
	conf->col.colors[3][4] = D_NEUTRAL_BROWN;
	conf->col.colors[4][0] = D_PASTEL_RED;
	conf->col.colors[4][1] = D_PASTEL_GREEN;
	conf->col.colors[4][2] = D_PASTEL_BLUE;
	conf->col.colors[4][3] = D_PASTEL_YELLOW;
	conf->col.colors[4][4] = D_PASTEL_BROWN;
}

static void		ft_init_palettes_2(t_conf *conf)
{
	conf->col.colors[5][0] = D_FLUO_MAGENTA;
	conf->col.colors[5][1] = D_FLUO_GREEN;
	conf->col.colors[5][2] = D_FLUO_CYAN;
	conf->col.colors[5][3] = D_FLUO_YELLOW;
	conf->col.colors[5][4] = D_FLUO_ORANGE;
	conf->col.colors[6][0] = D_CHILL_PURPLE;
	conf->col.colors[6][1] = D_CHILL_CYAN;
	conf->col.colors[6][2] = D_CHILL_YELLOW;
	conf->col.colors[6][3] = D_CHILL_RED;
	conf->col.colors[6][4] = D_CHILL_BLUE;
	conf->col.colors[7][0] = D_FIRE_HEAVY;
	conf->col.colors[7][1] = D_FIRE_MEDIUM_1;
	conf->col.colors[7][2] = D_FIRE_MEDIUM_2;
	conf->col.colors[7][3] = D_FIRE_MEDIUM_3;
	conf->col.colors[7][4] = D_FIRE_LIGHT;
	conf->col.colors[8][0] = D_OCEAN_BLUE_1;
	conf->col.colors[8][1] = D_OCEAN_BLUE_2;
	conf->col.colors[8][2] = D_OCEAN_CYAN_1;
	conf->col.colors[8][3] = D_OCEAN_CYAN_2;
	conf->col.colors[8][4] = D_OCEAN_PURPLE;
	conf->col.colors[9][0] = D_SNOW_WHITE;
	conf->col.colors[9][1] = D_SNOW_BLUE_1;
	conf->col.colors[9][2] = D_SNOW_BLUE_2;
	conf->col.colors[9][3] = D_SNOW_GREEN_1;
	conf->col.colors[9][4] = D_SNOW_GREEN_2;
}

static void		ft_init_palettes_3(t_conf *conf)
{
	conf->col.colors[10][0] = D_CAMO_SAND;
	conf->col.colors[10][1] = D_CAMO_GROUND;
	conf->col.colors[10][2] = D_CAMO_GRASS;
	conf->col.colors[10][3] = D_CAMO_LEAF;
	conf->col.colors[10][4] = D_CAMO_FOREST;
	conf->col.colors[11][0] = D_SAFARI_BROWN;
	conf->col.colors[11][1] = D_SAFARI_GREEN;
	conf->col.colors[11][2] = D_SAFARI_YELLOW;
	conf->col.colors[11][3] = D_SAFARI_ORANGE;
	conf->col.colors[11][4] = D_SAFARI_RED;
	conf->col.colors[12][0] = D_FAIRY_PINK;
	conf->col.colors[12][1] = D_FAIRY_BLUE;
	conf->col.colors[12][2] = D_FAIRY_GREEN;
	conf->col.colors[12][3] = D_FAIRY_PURPLE;
	conf->col.colors[12][4] = D_FAIRY_YELLOW;
	conf->col.colors[13][0] = D_ASSEMBLY_1;
	conf->col.colors[13][1] = D_ASSEMBLY_2;
	conf->col.colors[13][2] = D_ASSEMBLY_3;
	conf->col.colors[13][3] = D_ASSEMBLY_4;
	conf->col.colors[13][4] = D_ASSEMBLY_5;
	conf->col.colors[14][0] = D_NIGHT_BLUE;
	conf->col.colors[14][1] = D_NIGHT_PURPLE;
	conf->col.colors[14][2] = D_NIGHT_GREEN;
	conf->col.colors[14][3] = D_NIGHT_DARK;
	conf->col.colors[14][4] = D_NIGHT_MAGENTA;
}

static void		ft_init_palettes_4(t_conf *conf)
{
	conf->col.colors[15][0] = D_CYBERPUNK_PINK;
	conf->col.colors[15][1] = D_CYBERPUNK_GREEN;
	conf->col.colors[15][2] = D_CYBERPUNK_PURPLE;
	conf->col.colors[15][3] = D_CYBERPUNK_BLUE;
	conf->col.colors[15][4] = D_CYBERPUNK_FUSHIA;
	conf->col.colors[16][0] = D_SPIRIT_1;
	conf->col.colors[16][1] = D_SPIRIT_2;
	conf->col.colors[16][2] = D_SPIRIT_3;
	conf->col.colors[16][3] = D_SPIRIT_4;
	conf->col.colors[16][4] = D_SPIRIT_5;
	conf->col.colors[17][0] = D_TOXIC_1;
	conf->col.colors[17][1] = D_TOXIC_2;
	conf->col.colors[17][2] = D_TOXIC_3;
	conf->col.colors[17][3] = D_TOXIC_4;
	conf->col.colors[17][4] = D_TOXIC_5;
	conf->col.colors[18][0] = D_MATRIX_1;
	conf->col.colors[18][1] = D_MATRIX_2;
	conf->col.colors[18][2] = D_MATRIX_3;
	conf->col.colors[18][3] = D_MATRIX_4;
	conf->col.colors[18][4] = D_MATRIX_5;
	conf->col.colors[19][0] = D_GOOGLE_GREEN;
	conf->col.colors[19][1] = D_GOOGLE_BLUE;
	conf->col.colors[19][2] = D_GOOGLE_RED;
	conf->col.colors[19][3] = D_GOOGLE_ORANGE;
	conf->col.colors[19][4] = D_GOOGLE_WHITE;
}

void			ft_init_colors(t_conf *conf)
{
	conf->col.mode = 0;
	conf->col.palette = 20;
	conf->col.roll = 0;
	conf->col.bkg = 0;
	conf->col.bkg_pal = 1;
	conf->col.bkg_roll = 0;
	conf->col.rgb = 0;
	conf->col.red = 4;
	conf->col.green = 8;
	conf->col.blue = 16;
	conf->col.hsv = 0;
	conf->col.hue = 0;
	conf->col.saturation = 100;
	conf->col.value = 100;
	conf->col.psychedelic = 0;
	conf->col.epileptic = 0;
	conf->col.color_buddha = 0;
	ft_init_palettes_1(conf);
	ft_init_palettes_2(conf);
	ft_init_palettes_3(conf);
	ft_init_palettes_4(conf);
}
