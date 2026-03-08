/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:14:47 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 19:59:55 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_app_data	t_app_data;

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
	int				fork_id;
}					t_fork;

typedef enum e_philo_status
{
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	TOOK_FIRST_FORK,
	TOOK_SECOND_FORK,
	HAS_DIED,
}				t_philo_status;

typedef struct s_philo
{
	int				id;
	long			meals_counter;
	bool			has_reached_limit_nbr_meals;
	long			last_meal_time;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	pthread_mutex_t	philo_mutex;
	t_app_data		*app;
}					t_philo;

// app_data owns philo and forks

struct s_app_data
{
	long			nbr_philos;
	long			minimum_time_allowed;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	bool			has_limit_nbr_meals;
	long			limit_nbr_meals;
	long			simulation_start_time;
	bool			has_simulation_ended;
	t_philo			*philos;
	t_fork			*forks;
	bool			all_threads_ready;
	long			nbr_threads_running;
	pthread_mutex_t	app_mutex;
	pthread_mutex_t	print_mutex;
	pthread_t		monitor;
};

//	App lifecyle - app_create.c app_destroy.c
t_app_data	*app_create(int argc, char **argv);
void		app_destroy(t_app_data *app);
void		forks_destroy(t_app_data *app);

// App getters and setters:
//		app_get_and_set.c
int			get_has_simulation_ended(t_app_data *app, bool *out);
int			set_simulation_ended_and_all_threads_ready(t_app_data *app);
int			set_all_threads_ready(t_app_data *app);

// parse_input.c
int			parse_input(int argc, char **argv, t_app_data *app);

// time_utils.c
long		get_time_ms(void);
long		get_time_us(void);
int			feedback_based_usleep(long sleep_time_us, t_app_data *app);

// run_dinner_simulation.c
int			run_dinner_simulation(t_app_data *app);

// run_philo_routine.c
void		*run_philo_thread(void *philo_i);

// thread_safe_print.c
int			thread_safe_print(t_philo_status philo_status, t_philo *philo);

// run_monitor_thread.
void		*run_monitor_thread(void *data);

#endif
