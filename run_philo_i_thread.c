/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_i_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:47:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/04 20:49:08 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>

void	*run_philo_i_thread(void *philo_i)
{
	t_philo	*philo;

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


	
	
	return (NULL); // TODO.
}
