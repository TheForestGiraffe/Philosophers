/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:14:47 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/02 09:51:09 by pecavalc         ###   ########.fr       */
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
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_app_data	*app;
}				t_philo;

// app_data owns philo and forks

struct s_app_data
{
	long	nbr_philos;
	long	minimum_time_allowed;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	bool	has_limit_nbr_meals;
	long	limit_nbr_meals;
	long	simulation_start_time;
	bool	stop_simulation_flag; 		// When a philo dies, or all are full
	t_philo	*philos;
	t_fork	*forks;
};

// app.c
void	app_init(t_app_data *app);
int		app_setup(int argc, char **argv, t_app_data *app);
void	app_destroy(t_app_data *app);

// parse_input.c
int		parse_input(int argc, char **argv, t_app_data *app);

// get_time_ms.c
long	get_time_ms(void);

#endif
