/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:56:04 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 17:44:28 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*my_func(void	*arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->info;
	if (philo->index % 2 == 0)
		usleep(100);
	while (1)
	{
		take_fork(philo, data);
		print_msg(philo, philo->index, "is eating", data);
		pthread_mutex_lock(&data->died_check);
		philo->state = EATING;
		philo->last_meal = get_time();
		philo->nb_eat++;
		pthread_mutex_unlock(&data->died_check);
		ft_usleep(data->time_eat);
		philo->state = IS_NOT;
		pthread_mutex_unlock(&data->forks[philo->right_fork]);
		pthread_mutex_unlock(&data->forks[philo->left_fork]);
		slp_thi(philo, data);
	}
	return (NULL);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->nb_philo));
	if (!data->forks)
		return ;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) == -1)
			print_error("Error_in_mutex");
		i++;
	}
	if (pthread_mutex_init(&data->msg_check, NULL) == -1)
		print_error("Error_in_mutex");
	if (pthread_mutex_init(&data->died_check, NULL) == -1)
		print_error("Error_in_mutex");
}

void	create_thread(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	data->time = get_time();
	while (i < data->nb_philo)
	{
		philos[i].info = data;
		philos[i].state = IS_NOT;
		philos[i].state = IS_NOT;
		philos[i].index = i + 1;
		philos[i].left_fork = i;
		philos[i].nb_eat = 0;
		philos[i].right_fork = (i + 1) % philos->info->nb_philo;
		philos[i].last_meal = get_time();
		if (pthread_create(&philos[i].t1, NULL, my_func, &philos[i]) == -1)
			print_error("Error_in_thrad");
		i++;
	}
}
