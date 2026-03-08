/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:47:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 20:42:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <pthread.h>

static int	spinlock_until_all_threads_are_ready(t_app_data *app)
{
	while (1)
	{
		if (pthread_mutex_lock(&app->app_mutex))
			return (1);
		if (app->all_threads_ready)
		{
			if (pthread_mutex_unlock(&app->app_mutex))
				return (1);
			break ;
		}
		if (pthread_mutex_unlock(&app->app_mutex))
			return (1);
		usleep(50);
	}
	return (0);
}

void	*run_philo_thread(void *philo_i)
{
	t_philo	*philo;
	bool	simulation_ended;
	bool	has_reach_limit_nbr_meals;

	philo = (t_philo *)philo_i;
	simulation_ended = false;
	if (spinlock_until_all_threads_are_ready(philo->app))
		return (NULL);
	if (set_last_meal_time(philo))
		return (NULL);

	// Increment nbr_threads_running
	if (pthread_mutex_lock(&philo->app->app_mutex))
		return (NULL);
	philo->app->nbr_threads_running++;
	if (pthread_mutex_unlock(&philo->app->app_mutex))
		return (NULL);

	// start philo routine
	while (1)
	{
		if (get_has_simulation_ended(philo->app, &simulation_ended))
			return (NULL);
		if (simulation_ended)
			break ;
		if (get_has_reached_limit_nbr_meals(philo, &has_reach_limit_nbr_meals))
			return (NULL);
		if (has_reach_limit_nbr_meals)
			break ;
		if (philo_eat(philo))
			return (NULL);		
		if (philo_sleep(philo))
			return (NULL);
		if (philo_think(philo))
			return (NULL);
	}
	return (NULL);
}

