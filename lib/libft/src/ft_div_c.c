/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:24:50 by fdagbert          #+#    #+#             */
/*   Updated: 2020/11/18 19:57:48 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		ft_div_c(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = (a.real * b.real + a.imag * b.imag) /
					(b.real * b.real + b.imag * b.imag);
	result.imag = (a.imag * b.real - a.real * b.imag) /
					(b.real * b.real + b.imag * b.imag);
	return (result);
}
