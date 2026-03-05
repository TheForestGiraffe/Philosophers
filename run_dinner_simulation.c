/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_dinner_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:17:49 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/05 15:41:06 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static int	create_philo_threads(t_app_data *app)
{
	int		rc;
	long	i;
	
	i = 0;
	while (i < app->nbr_philos)
	{
		rc = pthread_create(&app->philos[i].thread_id, NULL,
							run_philo_thread, (void *)&app->philos[i]);
		if (rc)
			return (rc);
		i++;
	}
	return (0);
}

static int	set_all_threads_are_ready(t_app_data *app)
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
	long	i;
	int		rc;

	rc = create_philo_threads(app);
	if (rc)
		return (rc);
	
	// TODO: Create monitor thread

	app->simulation_start_time = get_time_ms();
	rc = set_all_threads_are_ready(app);
	if (rc)
		return (rc);
	i = 0;
	while (i < app->nbr_philos)
	{
		rc = pthread_join(app->philos[i].thread_id, NULL);
		if (rc)
			return (rc);
		i++;
	}
	return (0);
}
