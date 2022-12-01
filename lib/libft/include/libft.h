/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:12:03 by fdagbert          #+#    #+#             */
/*   Updated: 2020/08/12 19:06:28 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <fcntl.h>

typedef struct			s_complex
{
	double				real;
	double				imag;
}						t_complex;

typedef unsigned char	t_byte;

void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlen(const char *s);
size_t					ft_wcslen(const wchar_t *s);
int						ft_islower(int c);
int						ft_isdigit(int c);
int						ft_toupper(int c);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
char					*ft_strupcase(char *str);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strsub(const char *s, unsigned int start,
							size_t len);
char					**ft_strsplit(const char *s, char c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_str_is_numeric(char *str);
int						ft_get_next_line(const int fd, char **line);
int						ft_ceil(float n);
int						ft_break(int stop, int ret);
intmax_t				ft_atoim(const char *str);
int						ft_abs(int value);
float					ft_fabs(float value);
double					ft_dabs(double value);
double					ft_deg_to_rad(double degree);
t_complex				ft_add_c(t_complex a, t_complex b);
t_complex				ft_sub_c(t_complex a, t_complex b);
t_complex				ft_mult_c(t_complex a, t_complex b);
t_complex				ft_div_c(t_complex a, t_complex b);
t_complex				ft_pow_c(t_complex a, int power);

#endif
