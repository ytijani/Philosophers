/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_myfun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:38:14 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/19 10:07:14 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	print_msg(philo, philo->index, "has taken a fork", data);
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	print_msg(philo, philo->index, "has taken a fork", data);
}

void	slp_thi(t_philo *philo, t_data *data)
{
	print_msg(philo, philo->index, "is sleeping", data);
	ft_usleep(data->time_sleep);
	print_msg(philo, philo->index, "is thinking", data);
}

void	print_msg(t_philo *philo, int id, char *str, t_data *data)
{
	pthread_mutex_lock(&philo->info->msg_check);
	printf("%ld %d %s\n", (get_time() - data->time), id, str);
	pthread_mutex_unlock(&philo->info->msg_check);
}
