/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:47:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 13:34:14 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	get_has_reached_limit_nbr_meals(t_philo *philo, bool *out)
{
	int	rc;

	rc = pthread_mutex_lock(&philo->philo_mutex);
	if (rc)
		return (rc);
	*out = philo->has_reached_limit_nbr_meals;
	rc = pthread_mutex_unlock(&philo->philo_mutex);
	if (rc)
		return (rc);
	return (0);
}

static int	spinlock_until_all_threads_are_ready(t_app_data *app)
{
	int	rc;

	while (1)
	{
		rc = pthread_mutex_lock(&app->app_mutex);
		if (rc)
			return (rc);
		if (app->all_threads_ready)
		{
			rc = pthread_mutex_unlock(&app->app_mutex);
			if (rc)
				return (rc);
			break ;
		}
		rc = pthread_mutex_unlock(&app->app_mutex);
		if (rc)
			return (rc);
		usleep(50);
	}
	return (0);
}

void	*run_philo_thread(void *philo_i)
{
	int		rc;
	t_philo	*philo;
	bool	stop_thread;

	philo = (t_philo *)philo_i;
	stop_thread = false;
	rc = spinlock_until_all_threads_are_ready(philo->app);
	if (rc)
		return (NULL);
	
	// TODO: set last mean time

	while (1)
	{
		rc = get_has_simulation_ended(philo->app, &stop_thread);
		if (rc)
			return (NULL);
		if (stop_thread)
			break ;
		rc = get_has_reached_limit_nbr_meals(philo, &stop_thread);
		if (rc)
			return (NULL);
		if (stop_thread)
			break ;
		
		// Todo:
		//  - Eat
		//  - Sleep - write status and usleep
		//  - Think	
	}
	return (NULL); // TODO: (NULL?) how to properly return from a thread and catch return codes.
}

