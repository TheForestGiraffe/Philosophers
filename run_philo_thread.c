/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:47:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 16:49:36 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	eat(t_philo *philo)
{
	int	rc;

	// Take (lock) forks
	rc = pthread_mutex_lock(philo->first_fork);
	if (rc)
		return (rc);
	thread_safe_print(TOOK_FIRST_FORK, philo);
	rc = pthread_mutex_lock(philo->second_fork);
	if (rc)
	{
		pthread_mutex_unlock(philo->first_fork);
		return (rc);
	}
	thread_safe_print(TOOK_SECOND_FORK, philo);

	// Eat
	rc = pthread_mutex_lock(&philo->philo_mutex);
	if (rc)
		return (rc);
	philo->last_meal_time = get_time_ms;
	feedback_based_usleep(philo->app->time_to_eat, philo->app);
	philo->meals_counter++;
	if (philo->meals_counter > 0
		&& philo->meals_counter >= philo->app->limit_nbr_meals)
		philo->has_reached_limit_nbr_meals = true;
	
	// Release (unlock) forks
	rc = pthread_mutex_unlock(philo->first_fork);
	if (rc)
		return (rc);
	rc = pthread_mutex_unlock(philo->second_fork);
	if (rc)
		return (rc);
}

static int	sleep(t_philo *philo)
{
	int	rc;
	
	rc = thread_safe_print(IS_SLEEPING, philo);
	if (rc)
		return (rc);
	feedback_based_usleep(philo->app->time_to_sleep * 1000L, philo->app);
	return (0);
}

// TODO
static int	think(t_philo *philo)
{
	int	rc;

	rc = thread_safe_print(IS_THINKING, philo);
	if (rc)
		return (rc);
	return (0);
}

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
	
	// TODO: set last meal time

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
		rc = eat(philo);
		if (rc)
			return (rc);		
		rc = sleep(philo);
		if (rc)
			return (rc);
		// TODO: think
		rc = think(philo);
		if (rc)
			return (rc);
	}
	return (NULL); // TODO: (NULL?) how to properly return from a thread and catch return codes.
}

