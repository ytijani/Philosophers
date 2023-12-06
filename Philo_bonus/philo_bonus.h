/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:45:36 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 17:54:28 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>

# define EATING 1
# define IS_NOT 0

typedef struct s_data
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	long			time;
	int				must_eat;
	sem_t			*forks;
	sem_t			*died_check;
	sem_t			*msg_check;
	int				died;
}				t_data;

typedef struct s_philo
{
	int				index;
	int				right_fork;
	int				left_fork;
	long			last_meal;
	int				state;
	int				nb_eat;
	pid_t			id;
	pthread_t		t1;
	t_data			*info;
}				t_philo;

/************Function ****************/
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
/************Help function ****************/
void	print_msg(int id, char *str, t_data *data);
void	my_func(void	*arg);
int		check_death(long time, long last_meal, int time_die);
void	*checking_death(void	*arg);
void	create_process(t_philo *philo, t_data *data);
int		death(t_philo *philo, t_data *data);
int		eat_enough(t_philo *philo, t_data *data);
void	kill_all(t_data *data, t_philo *philo);
void	wait_pr(t_philo *philo, t_data *data, int status);
/*************time_function****************/
long	get_time(void);
void	ft_usleep(long n);
/************Error****************/
int		ft_check(char **av);
int		ft_isdigit(int c);
#endif
