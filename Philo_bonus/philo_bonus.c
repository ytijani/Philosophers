/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:27:58 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 17:49:01 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		kill(philo[i].id, SIGKILL);
	exit(0);
}

int	death(t_philo *philo, t_data *data)
{
	sem_wait(data->died_check);
	if ((check_death(get_time(), philo->last_meal, data->time_die) == 1)
		&& philo->state == IS_NOT)
	{
		sem_wait(data->msg_check);
		printf("%ld %d died\n", (get_time() - data->time), philo->index);
		return (1);
	}
	sem_post(data->died_check);
	return (0);
}

void	init_data(t_data	*data, char **av, int ac)
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

void	init_semaphore(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("died_check");
	sem_unlink("msg_check");
	data->forks = sem_open("forks", O_CREAT, 0644, data->nb_philo);
	if (data->forks < 0)
		return ;
	data->died_check = sem_open("died_check", O_CREAT, 0644, 1);
	if (data->forks < 0)
		return ;
	data->msg_check = sem_open("msg_check", O_CREAT, 0644, 1);
	if (data->forks < 0)
		return ;
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
	if (data->nb_philo == 0 || data->time_die == 0
		|| data->time_eat == 0 || data->time_sleep == 0)
		return (0);
	init_semaphore(data);
	create_process(philo, data);
	return (0);
}
