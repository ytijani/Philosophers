/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:55:14 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 17:53:46 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	struct timeval	start;
	long			res;

	gettimeofday(&start, NULL);
	res = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (res);
}

void	ft_usleep(long n)
{
	long long	l;

	l = get_time() + n;
	while (get_time() < l)
		usleep(300);
}

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
}

int	check_death(long time, long last_meal, int time_die)
{
	if ((time - last_meal) >= time_die)
		return (1);
	return (0);
}
