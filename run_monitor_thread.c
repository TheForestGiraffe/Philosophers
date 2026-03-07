/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 22:22:41 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	are_all_philos_full(t_app_data *app, bool *all_philos_full)
{
	int		rc;
	long	i;

	i = 0;
	while (i < app->nbr_philos)
	{
		rc = pthread_mutex_lock(&app->philos[i].philo_mutex);
		if (rc)
			return (rc);
		if (app->philos[i].has_reached_limit_nbr_meals == false)
		{
			rc = pthread_mutex_unlock(&app->philos[i].philo_mutex);
			if (rc)
				return (rc);
			*all_philos_full = false;
			return (0);
		}
		rc = pthread_mutex_unlock(&app->philos[i].philo_mutex);
		if (rc)
			return (rc);
		i++;
	}
	*all_philos_full = true;
	return (0);
}

static int	check_if_a_philo_died(t_app_data *app, bool *philo_died)
{
	int		rc;
	long	i;

	i = 0;
	while (i < app->nbr_philos)
	{
		rc = pthread_mutex_lock(&app->philos[i].philo_mutex);
		if (rc)
			return (rc);
		if ((get_time_ms() - app->philos[i].last_meal_time) > app->time_to_die)
			*philo_died = true;
		rc = pthread_mutex_unlock(&app->philos[i].philo_mutex);
		if (rc)
			return (rc);
		if (*philo_died)
		{
			rc = thread_safe_print(HAS_DIED, &app->philos[i]);
			if (rc)
				return (rc);
			break ;
		}
		i++;
	}
	return (0);
}

static int	get_all_threads_running(t_app_data *app, bool *all_threads_running)
{
	int	rc;

	rc = pthread_mutex_lock(&app->app_mutex);
	if (rc)
		return (rc);
	if (app->nbr_threads_running == app->nbr_philos)
		*all_threads_running = true;
	rc = pthread_mutex_unlock(&app->app_mutex);
	if (rc)
		return (rc);
	return (0);
}

void	*run_monitor_thread(void *data)
{
	int			rc;
	t_app_data	*app;
	bool		all_threads_running;
	bool		philo_died;
	bool		simulation_ended;
	bool		all_philos_are_full;

	app = (t_app_data *)data;
	
	// Check if all threads are running or simulation ended
	all_threads_running = false;
	while (1)
	{
		rc = get_all_threads_running(app, &all_threads_running);
		if (rc)
		{
			stop_simulation_and_release_threads(app);
			return (NULL);
		}
		if (all_threads_running)
			break ;
		rc = get_has_simulation_ended(app, &simulation_ended);
		if (rc)
		{
			stop_simulation_and_release_threads(app);
			return (NULL);
		}
		if (simulation_ended)
			return (NULL);
		usleep(100);
	}

	// Check if a philo died or is full
	philo_died = false;
	all_philos_are_full = false;
	while (1)
	{
		rc = get_has_simulation_ended(app, &simulation_ended);
		if (rc)
		{
			stop_simulation_and_release_threads(app);
			return (NULL);
		}
		if (simulation_ended)
			return (NULL);

		// has any philo died?	
		rc = check_if_a_philo_died(app, &philo_died);
		if (rc)
		{
			stop_simulation_and_release_threads(app);
			return (NULL);
		}
		if (philo_died)
			break ;
		
		// are all philos full?
		rc = are_all_philos_full(app, &all_philos_are_full);
		if (rc)
		{
			stop_simulation_and_release_threads(app);
			return (NULL);
		}
		if (all_philos_are_full)
			break ;
		usleep(100);
	}
	stop_simulation_and_release_threads(app);
	return (NULL);
}
