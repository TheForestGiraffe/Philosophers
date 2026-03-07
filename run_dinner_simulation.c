/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_dinner_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:17:49 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 21:23:44 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	stop_simulation_and_release_threads(t_app_data *app)
{
	int	rc;

	rc = pthread_mutex_lock(&app->app_mutex);
	if (rc)
		return (rc);
	app->has_simulation_ended = true;
	app->all_threads_ready = true;
	rc = pthread_mutex_unlock(&app->app_mutex);
	if (rc)
		return (rc);
	return (0);
}

static int	join_philo_threads(t_app_data *app, long count)
{
	long	i;
	int		rc;

	i = 0;
	while (i < count)
	{
		rc = pthread_join(app->philos[i].thread_id, NULL);
		if (rc)
			return (rc);
		i++;
	}
	return (0);
}

static int	create_philo_threads(t_app_data *app)
{
	int		rc;
	int		rc2;
	long	i;
	long	j;

	i = 0;
	while (i < app->nbr_philos)
	{
		rc = pthread_create(&app->philos[i].thread_id, NULL,
				run_philo_thread, (void *)&app->philos[i]);
		if (rc)
		{
			rc2 = stop_simulation_and_release_threads(app);
			if (rc2)
				return (rc2);
			j = 0;
			while (j < i)
			{
				rc2 = pthread_join(app->philos[j].thread_id, NULL);
				if (rc2)
					return (rc2);
				j++;
			}
			return (rc);
		}
		i++;
	}
	return (0);
}

static int	set_all_threads_ready(t_app_data *app)
{
	int	rc;

	rc = pthread_mutex_lock(&app->app_mutex);
	if (rc)
		return (rc);
	app->all_threads_ready = true;
	rc = pthread_mutex_unlock(&app->app_mutex);
	if (rc)
		return (rc);
	return (0);
}

int	run_dinner_simulation(t_app_data *app)
{
	int	rc;
	int	cleanup_rc;

	rc = create_philo_threads(app);
	if (rc)
		return (rc);
	rc = pthread_create(&app->monitor, NULL, run_monitor_thread, app);
	if (rc)
	{
		cleanup_rc = stop_simulation_and_release_threads(app);
		if (cleanup_rc)
			return (cleanup_rc);
		cleanup_rc = join_philo_threads(app, app->nbr_philos);
		if (cleanup_rc)
			return (cleanup_rc);
		return (rc);
	}
	app->simulation_start_time = get_time_ms();
	rc = set_all_threads_ready(app);
	if (rc)
	{
		cleanup_rc = stop_simulation_and_release_threads(app);
		if (cleanup_rc)
			return (cleanup_rc);
		cleanup_rc = pthread_join(app->monitor, NULL);
		if (cleanup_rc)
			return (cleanup_rc);
		cleanup_rc = join_philo_threads(app, app->nbr_philos);
		if (cleanup_rc)
			return (cleanup_rc);
		return (rc);
	}
	rc = pthread_join(app->monitor, NULL);
	if (rc)
		return (rc);
	rc = join_philo_threads(app, app->nbr_philos);
	if (rc)
		return (rc);
	return (0);
}
