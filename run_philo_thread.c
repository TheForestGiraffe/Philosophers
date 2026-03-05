/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:47:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/05 12:01:50 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>

int	get_app_stop_simulation(t_app_data *app, bool *out)
{
	int	rc;

	rc = pthread_mutex_lock(&app->app_mutex);
	if (!rc)
		return (rc);
	*out = app->stop_simulation;
	rc = pthread_mutex_unlock(&app->app_mutex);
	if (!rc)
		return (rc);
	return (0);
}

void	*run_philo_thread(void *philo_i)
{
	t_philo	*philo;
	bool	stop_simulation;
	int		rc;
	
	philo = (t_philo *)philo_i;
	
	// Thread start sync - spinlock: Wait for all threads to be ready
	while (1)
	{
		if (pthread_mutex_lock(&philo->app->app_mutex))
			return (NULL);
		if (philo->app->all_threads_ready)
		{
			if (pthread_mutex_unlock(&philo->app->app_mutex));
				return (NULL);
			break;
		}
		if (pthread_mutex_unlock(&philo->app->app_mutex))
			return (NULL);
	}

	// Check if simulation has ended
	rc = get_app_stop_simulation(philo->app, &stop_simulation);
	if (!rc)
		return (NULL);
	while (!stop_simulation)
	{
		
	}
		
	return (NULL); // TODO: (NULL?) how to properly return from a thread and catch it.
}

