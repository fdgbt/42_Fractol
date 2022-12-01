/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:26:25 by fdagbert          #+#    #+#             */
/*   Updated: 2017/11/30 15:49:30 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fillstr(int nbr, int size, char *str)
{
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr *= (-1);
	}
	if (nbr == -2147483648)
	{
		str[1] = '2';
		nbr = 147483648;
	}
	str[size] = '\0';
	size--;
	while (nbr > 0)
	{
		str[size] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
}

char			*ft_itoa(int n)
{
	int		size;
	int		temp;
	char	*str;

	size = 0;
	temp = n;
	str = NULL;
	if (n <= 0)
	{
		size++;
		temp *= (-1);
	}
	if (n == -2147483648)
		size = 11;
	else
		while (temp > 0)
		{
			size++;
			temp /= 10;
		}
	if (!(str = ft_strnew(size)))
		return (NULL);
	ft_fillstr(n, size, str);
	return (str);
}
