/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:11:08 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 17:49:54 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if ((check_death(get_time(), philo[i].last_meal, data->time_die) == 1)
			&& (philo[i].state == IS_NOT))
		{
			pthread_mutex_lock(&data->msg_check);
			printf("%ld %d died\n", (get_time() - data->time), philo[i].index);
			return (1);
		}
		i++;
	}
	return (0);
}

int	eat_enough(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (philo[i].nb_eat < data->must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	checking_death(t_philo *philo, t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->died_check);
		if (death(philo, data) == 1)
			return ;
		if (data->must_eat != -1 && eat_enough(philo, data) == 1)
			return ;
		pthread_mutex_unlock(&data->died_check);
		usleep(100);
	}
}

void	init_data(t_data *data, char **av, int ac)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->died = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	if ((ac != 5 && ac != 6) || ft_check(av) == 0)
	{
		ft_putstr_fd("Error", 2);
		return (0);
	}
	philo = malloc(sizeof(t_philo) * (ft_atoi(av[1])));
	if (!philo)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	init_data(data, av, ac);
	init_mutex(data);
	create_thread(philo, data);
	if (data->nb_philo == 0 || data->time_die == 0
		|| data->time_eat == 0 || data->time_sleep == 0)
		return (0);
	checking_death(philo, data);
	return (0);
}
