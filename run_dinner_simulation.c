/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_dinner_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:17:49 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/02 11:53:19 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	run_dinner_simulation(t_app_data *app)
{
	int	i;
	int	rc;

	// Create all threads
	i = 0;
	while (i < app->nbr_philos)
	{
		rc = pthread_create(&app->philos[i].thread_id, NULL,
							run_philo_i_thread, (void *)&app->philos[i]);
		if (rc)
			return (rc);
		i++;
	}

	// Set all threads ready flag as true
	rc = pthread_mutex_lock(&app->app_mutex);
	if (rc)
		return (rc);
	app->all_threads_ready = true;
	rc = pthread_mutex_unlock(&app->app_mutex);
	if (rc)
		return (rc);
 
	// create monitor thread
	// synchronize simulatio begin

	return (0);
}
