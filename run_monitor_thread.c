/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 23:20:31 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	are_all_philos_full(t_app_data *app, bool *all_philos_full)
{
	long	i;

	i = 0;
	while (i < app->nbr_philos)
	{
		if (pthread_mutex_lock(&app->philos[i].philo_mutex))
			return (1);
		if (app->philos[i].has_reached_limit_nbr_meals == false)
		{
			if (pthread_mutex_unlock(&app->philos[i].philo_mutex))
				return (1);
			*all_philos_full = false;
			return (0);
		}
		if (pthread_mutex_unlock(&app->philos[i].philo_mutex))
			return (1);
		i++;
	}
	*all_philos_full = true;
	return (0);
}

static int	has_a_philo_died(t_app_data *app, bool *philo_died)
{
	long	i;

	i = 0;
	while (i < app->nbr_philos)
	{
		if (pthread_mutex_lock(&app->philos[i].philo_mutex))
			return (1);
		if ((get_time_ms() - app->philos[i].last_meal_time) >= app->time_to_die)
			*philo_died = true;
		if (pthread_mutex_unlock(&app->philos[i].philo_mutex))
			return (1);
		if (*philo_died)
		{
			if (thread_safe_printf(HAS_DIED, &app->philos[i]))
				return (1);
			break ;
		}
		i++;
	}
	return (0);
}

static int	spinlock_until_all_threads_running(t_app_data *app,
				bool *simulation_ended)
{
	while (1)
	{
		if (pthread_mutex_lock(&app->app_mutex))
			break ;
		if (app->nbr_threads_running == app->nbr_philos)
		{
			if (pthread_mutex_unlock(&app->app_mutex))
				break ;
			return (0);
		}
		if (pthread_mutex_unlock(&app->app_mutex))
			break ;
		if (get_has_simulation_ended(app, simulation_ended))
			break ;
		if (*simulation_ended == true)
			return (0);
		usleep(100);
	}
	set_simulation_ended_and_all_threads_ready(app);
	return (1);
}

static int	spinlock_until_philo_died_or_is_full(t_app_data *app)
{
	bool		simulation_ended;
	bool		philo_died;
	bool		all_philos_are_full;

	simulation_ended = false;
	philo_died = false;
	all_philos_are_full = false;
	while (1)
	{
		if (get_has_simulation_ended(app, &simulation_ended)
			|| has_a_philo_died(app, &philo_died)
			|| are_all_philos_full(app, &all_philos_are_full))
			break ;
		if (simulation_ended)
			return (0);
		if (philo_died || all_philos_are_full)
		{
			if (set_simulation_ended_and_all_threads_ready(app))
				return (1);
			return (0);
		}
		usleep(100);
	}
	set_simulation_ended_and_all_threads_ready(app);
	return (1);
}

void	*run_monitor_thread(void *data)
{
	t_app_data	*app;
	bool		simulation_ended;

	app = (t_app_data *)data;
	simulation_ended = false;
	if (spinlock_until_all_threads_running(app, &simulation_ended))
		return ((void *)1);
	if (simulation_ended)
		return (NULL);
	if (spinlock_until_philo_died_or_is_full(app))
		return ((void *)1);
	return (NULL);
}
