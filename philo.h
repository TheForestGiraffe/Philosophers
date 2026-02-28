/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:14:47 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/28 15:15:12 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdbool.h>

typedef struct s_app_data t_app_data;

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
	int				fork_id;
}					t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		has_reached_limit_nbr_meals;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_app_data	*app;
}				t_philo;

struct s_app_data
{
	long	nbr_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	limit_nbr_meals; 			// Also a flag ATM. When -1, no limit
	long	simulation_start_time;
	long	simulation_end_time; 		// When a philo dies, or all are full
	t_philo	*philo_array;
	t_fork	*fork_array;
};

#endif
