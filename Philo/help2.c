/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:28:30 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 17:29:57 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long n)
{
	long long	l;

	l = get_time() + n;
	while (get_time() < l)
		usleep(300);
}

void	print_error(char *str)
{
	ft_putstr_fd (str, 2);
}

int	check_death(long time, long last_meal, int time_die)
{
	if ((time - last_meal) >= time_die)
		return (1);
	return (0);
}

long	get_time(void)
{
	struct timeval	start;
	long			res;

	gettimeofday(&start, NULL);
	res = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (res);
}

int	ft_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
