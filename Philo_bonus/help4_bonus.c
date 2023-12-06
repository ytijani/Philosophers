/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help4_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:21:54 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 17:51:04 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	wait_pr(t_philo *philo, t_data *data, int status)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (status == EXIT_SUCCESS)
			break ;
		else
		{
			kill_all(data, philo);
			exit (0);
		}
	}
	kill_all(data, philo);
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
