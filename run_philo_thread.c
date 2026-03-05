/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:47:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/05 12:48:10 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	spinlock_while_all_threads_are_ready(t_app_data *app)
{
	int	rc;

	while (1)
	{
		rc = pthread_mutex_lock(&app->app_mutex);
		if (rc)
			return (rc);
		if (app->are_all_threads_ready)
		{
			rc = pthread_mutex_unlock(&app->app_mutex);
			if (rc)
				return (rc);
			break;
		}
		rc = pthread_mutex_unlock(&app->app_mutex);
		if (rc)
			return (rc);
		usleep(50);
	}
	return (0);
}
	
static int	get_has_simulation_ended(t_app_data *app, bool *out)
{
	int	rc;

	rc = pthread_mutex_lock(&app->app_mutex);
	if (rc)
		return (rc);
	*out = app->has_simulation_ended;
	rc = pthread_mutex_unlock(&app->app_mutex);
	if (rc)
		return (rc);
	return (0);
}

void	*run_philo_thread(void *philo_i)
{
	int		rc;
	t_philo	*philo;
	bool	has_simulation_ended;

	philo = (t_philo *)philo_i;
	rc = spinlock_while_all_threads_are_ready(philo->app);
	if (rc)
		return (NULL);
	while (1)
	{
		rc = get_has_simulation_ended(philo->app, &has_simulation_ended);
		if (rc)
			return (NULL);
		if (has_simulation_ended)
			break ;
		// Todo:
		//  - Check if full
		//  - Eat
		//  - Sleep - write status and usleep
		//  - Think	
	}
	return (NULL); // TODO: (NULL?) how to properly return from a thread and catch it.
}

