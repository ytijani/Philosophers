/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help3.bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:12:24 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 17:52:47 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	slp_thi(t_philo *philo, t_data *data)
{
	print_msg(philo->index, "is sleeping", data);
	ft_usleep(data->time_sleep);
	print_msg(philo->index, "is thinking", data);
}

void	print_msg(int id, char *str, t_data *data)
{
	sem_wait(data->msg_check);
	printf("%ld %d %s\n", (get_time() - data->time), id, str);
	sem_post(data->msg_check);
}

void	*checking_death(void	*arg)
{
	t_philo		*philo;
	t_data		*data;

	philo = (t_philo *)arg;
	data = philo->info;
	while (1)
	{
		if (death(philo, data) == 1)
			exit(EXIT_SUCCESS);
		if (data->must_eat != -1 && philo->nb_eat >= data->must_eat)
			exit (EXIT_FAILURE);
		usleep(100);
	}
	return (NULL);
}

void	create_process(t_philo *philo, t_data *data)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	data->time = get_time();
	while (i < data->nb_philo)
	{
		philo[i].info = data;
		philo[i].state = IS_NOT;
		philo[i].last_meal = get_time();
		philo[i].index = i + 1;
		philo[i].nb_eat = 0;
		philo[i].id = fork();
		if (philo[i].id < 0)
		{
			printf("eroor fork\n");
			exit(1);
		}
		if (!philo[i].id)
			my_func(&philo[i]);
		i++;
		usleep(100);
	}
	wait_pr(philo, data, status);
}

void	my_func(void	*arg)
{
	t_philo		*philo;
	t_data		*data;
	pthread_t	t1;

	philo = (t_philo *)arg;
	data = philo->info;
	pthread_create(&t1, NULL, checking_death, philo);
	while (1)
	{
		sem_wait(data->forks);
		print_msg(philo->index, "has taken a fork", data);
		sem_wait(data->forks);
		print_msg(philo->index, "has taken a fork", data);
		print_msg(philo->index, "is eating", data);
		sem_wait(data->died_check);
		philo->state = EATING;
		philo->last_meal = get_time();
		sem_post(data->died_check);
		ft_usleep(data->time_eat);
		philo->nb_eat++;
		philo->state = IS_NOT;
		sem_post(data->forks);
		sem_post(data->forks);
		slp_thi(philo, data);
	}
}
