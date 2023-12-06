/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:47:32 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/08 19:30:40 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_set(int *i, long long *nbr, int *n)
{
	*i = 0;
	*nbr = 0;
	*n = 1;
}

int	ft_atoi(char *str)
{
	int			i;
	long long	nbr;
	int			n;

	ft_set(&i, &nbr, &n);
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		if ((n == -1 && (nbr * -1) < INT_MIN) || ((n == 1) && nbr > INT_MAX))
			return (0);
		i++;
	}
	if (str[i] || !i)
		return (0);
	return (nbr * n);
}
