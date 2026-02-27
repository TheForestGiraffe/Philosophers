/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:14:47 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/26 20:16:01 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIM_DATA_H
# define SIM_DATA_H

#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	long		time_last_meal;
}				t_philo;

typedef struct s_data {
	long			nr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nr_times_each_must_eat;
	long			start_time;
	t_philo			*philos;
	pthread_t		*philo_threads;
	pthread_mutex_t	*forks;
}					t_data;

/* parser */
int				parse(int argc, char **argv, t_data *data);
int				ft_strtol(const char *str, long *number);

/* forks.c*/
pthread_mutex_t	*forks_create(const long nr_philos);
void			forks_destroy(const long nr_forks_to_destroy,
					pthread_mutex_t **forks);

/* philos.c */
t_philo		*philos_create(const long nr_philos);
void		philos_set_time_last_meal(long start_time, long nr_philos,
				t_philo *philos);

/* get_time.c */
long	get_time_ms(void);

#endif
