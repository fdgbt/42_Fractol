/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_date.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:04:14 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/24 15:04:16 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_is_leap(time_t year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return (1);
	else
		return (0);
}

static void		ft_calc_timestamp(t_time *t, int c, int a, int m)
{
	static const int	daysbymonth[] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	while (t->total_day >= 365 + t->leap)
	{
		t->total_day -= 365 + t->leap;
		t->year++;
		t->leap = ft_is_leap(t->year);
	}
	t->week = t->total_day / 7 + 1;
	t->month = 1;
	while (t->total_day >= daysbymonth[t->month])
	{
		t->total_day -= daysbymonth[t->month];
		if (t->leap && t->month == 2)
			t->total_day -= 1;
		t->month++;
	}
	t->total_day++;
	c = (14 - t->month) / 12;
	a = t->year - c;
	m = t->month + 12 * c - 2;
	t->day = (t->total_day + a + a / 4 - a / 100 + a / 400 + (31 * m) / 12) % 7;
}

void			ft_get_date(char *date)
{
	time_t		timestamp;
	t_time		t;

	timestamp = time(NULL);
	t.total_day = timestamp / 86400;
	t.year = D_EPOCH;
	t.leap = ft_is_leap(t.year);
	t.hour = timestamp % 86400 / 3600;
	t.minute = (timestamp % 86400 % 3600) / 60;
	t.second = timestamp % 86400 % 60;
	ft_calc_timestamp(&t, 0, 0, 0);
	ft_str_date(date, t);
}
