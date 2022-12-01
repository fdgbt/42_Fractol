/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:24:50 by fdagbert          #+#    #+#             */
/*   Updated: 2020/11/18 19:57:48 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex	ft_pow_c(t_complex c, int power)
{
	t_complex	result;

	result = c;
	while (power > 1)
	{
		result = ft_mult_c(result, c);
		power--;
	}
	return (result);
}
