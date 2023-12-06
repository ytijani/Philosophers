/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytijani <ytijani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:11:20 by ytijani           #+#    #+#             */
/*   Updated: 2022/06/23 14:26:13 by ytijani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

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
	int				died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	died_check;
	pthread_mutex_t	msg_check;
}	t_data;

typedef struct s_philo
{
	int				index;
	int				right_fork;
	int				left_fork;
	long			last_meal;
	int				nb_eat;
	int				state;
	pthread_t		t1;
	t_data			*info;
}	t_philo;

/************Function ****************/
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
void	print_msg(t_philo *philo, int id, char *str, t_data *data);
/************help_function******************/
void	take_fork(t_philo *philo, t_data *data);
void	slp_thi(t_philo *philo, t_data *data);
void	print_msg(t_philo *philo, int id, char *str, t_data *data);
/************init_thread********************/
void	create_thread(t_philo *philos, t_data *data);
void	join_thread(t_philo *philo);
/************init_mutex********************/
void	init_mutex(t_data *data);
/************print_Error******************/
void	print_error(char *str);
/*************time_function****************/
long	get_time(void);
int		check_death(long time, long last_meal, int time_die);
void	ft_usleep(long n);
/************Error****************/
int		ft_check(char **av);
int		ft_isdigit(int c);
#endif
