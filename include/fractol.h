/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:46:59 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/23 22:47:06 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <time.h>
# include "mlx.h"
# include "X11/Xlib.h"
# include "libft.h"
# include "ft_printf.h"
# include "structs.h"
# include "errors.h"
# include "colors.h"
# include "keys_linux.h"

void				ft_init_conf(t_conf *conf);
void				ft_init_names(t_conf *conf);
void				ft_init_colors(t_conf *conf);
int					ft_check_args(int err, int j, char **argv, t_conf *conf);
int					ft_check_opt_arg(int i, int j, char *argv, t_conf *conf);
int					ft_init_grid(t_conf *conf);
void				ft_init_border(int i, t_conf *conf);
void				ft_set_grid(t_conf *conf);
void				ft_set_fractal(t_conf *conf);
void				ft_set_buddha(int color, t_point actual, t_conf *conf);
void				ft_set_pthr(t_conf *conf);
void				ft_set_ssaa(t_conf *conf);
void				ft_set_img(t_point actual, t_conf *conf);
void				ft_set_img_full(t_conf *conf);
int					ft_set_gradient(int iteration, int bkmirror, t_conf *conf);
int					ft_set_hsv(int hue, t_conf *conf);
void				ft_set_fdf(t_conf *conf);
void				ft_get_date(char *date);
void				ft_str_date(char *date, t_time t);
void				fractal_mandelbrot(int i, t_point actual, t_conf *conf);
void				fractal_julia(int i, t_point actual, t_conf *conf);
void				fractal_burning_ship(int i, t_point actual, t_conf *conf);
void				fractal_multibrot(int i, t_point actual, t_conf *conf);
void				fractal_buddhabrot(t_conf *conf);
void				fractal_newton(int col, t_point actual, t_conf *conf);
void				fractal_koch(t_conf *conf);
void				fractal_sierpinski(t_conf *conf);
void				fractal_barnsley(t_conf *conf);
void				ft_bresenham(int i, t_grid start, t_grid end, t_conf *conf);
int					ft_start_hook(t_conf *conf);
int					ft_press_key(int key, t_conf *param);
void				ft_press_key_letter(int key, t_conf *conf);
void				hook_clean_screen(t_conf *conf);
void				hook_clean_parameter(t_conf *conf);
void				hook_clean_color(t_conf *conf);
void				hook_zoom(int dir, t_conf *conf);
void				hook_iteration(int dir, t_conf *conf);
void				hook_level(int dir, t_conf *conf);
void				hook_sample(int dir, t_conf *conf);
void				hook_filter(int dir, t_conf *conf);
void				hook_fractal(int fractal, t_conf *conf);
void				hook_mode(int dir, t_conf *conf);
void				hook_palette(int dir, t_conf *conf);
void				hook_check_pal(t_conf *conf);
void				hook_roll(int dir, t_conf *conf);
void				hook_check_roll(t_conf *conf);
void				hook_bkg(int dir, t_conf *conf);
void				hook_check_bkg(t_conf *conf);
void				hook_set_bkg(t_conf *conf);
void				hook_rgb(int dir, t_conf *conf);
void				hook_check_rgb(t_conf *conf);
void				hook_set_rgb(int dir, t_conf *conf);
void				hook_hsv(int dir, t_conf *conf);
void				hook_check_hsv(t_conf *conf);
void				hook_set_hsv(int dir, t_conf *conf);
void				hook_psy(int dir, t_conf *conf);
void				hook_set_psy(int dir, t_conf *conf);
int					hook_move_mouse(int x, int y, t_conf *conf);
void				hook_move_axes(int dir, int mouse, t_conf *conf);
void				hook_move_c(int dir, t_conf *conf);
void				hook_switch_julia(int dir, t_conf *conf);
void				hook_ssaa(int dir, t_conf *conf);
void				ft_print_float(char *text, float value);
void				ft_print_buddha(t_conf *conf);
void				ft_print_nebula(t_rgb *col, t_point actual, t_conf *conf);
void				ft_print_hud(t_conf *conf);
void				ft_print_infos(int y, int x1, int x2, t_conf *conf);
void				ft_print_params(int y, int x1, int x2, t_conf *conf);
void				ft_print_colors(int y, int x1, int x2, t_conf *conf);
void				ft_print_modes(int y, int x1, int x2, t_conf *conf);
void				ft_print_full_cmd(int y, int x1, int x2, t_conf *conf);
void				ft_print_full_next(int y, int x1, int x2, t_conf *conf);
int					ft_end(int error, t_conf *conf);

#endif
