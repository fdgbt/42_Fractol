/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_date.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:11:54 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:11:55 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_fill_minute_second(char *itoa, char *date, t_time t)
{
	if (t.minute > 9)
	{
		itoa = ft_itoa(t.minute);
		date[11] = itoa[0];
		date[12] = itoa[1];
		free(itoa);
	}
	else
	{
		date[11] = '0';
		date[12] = t.minute + '0';
	}
	if (t.second > 9)
	{
		itoa = ft_itoa(t.second);
		date[13] = itoa[0];
		date[14] = itoa[1];
		free(itoa);
	}
	else
	{
		date[13] = '0';
		date[14] = t.second + '0';
	}
	date[15] = 0;
}

static void		ft_fill_day_hour(char *itoa, char *date, t_time t)
{
	if (t.day > 9)
	{
		itoa = ft_itoa(t.day);
		date[6] = itoa[0];
		date[7] = itoa[1];
		free(itoa);
	}
	else
	{
		date[6] = '0';
		date[7] = t.day + '0';
	}
	date[8] = '_';
	if (t.hour > 9)
	{
		itoa = ft_itoa(t.hour);
		date[9] = itoa[0];
		date[10] = itoa[1];
		free(itoa);
	}
	else
	{
		date[9] = '0';
		date[10] = t.hour + '0';
	}
}

static void		ft_fill_year_month(char *itoa, char *date, t_time t)
{
	itoa = ft_itoa(t.year);
	date[0] = itoa[0];
	date[1] = itoa[1];
	date[2] = itoa[2];
	date[3] = itoa[3];
	free(itoa);
	if (t.month > 9)
	{
		itoa = ft_itoa(t.month);
		date[4] = itoa[0];
		date[5] = itoa[1];
		free(itoa);
	}
	else
	{
		date[4] = '0';
		date[5] = t.month + '0';
	}
}

void			ft_str_date(char *date, t_time t)
{
	char	*itoa;

	itoa = NULL;
	ft_fill_year_month(itoa, date, t);
	ft_fill_day_hour(itoa, date, t);
	ft_fill_minute_second(itoa, date, t);
}
