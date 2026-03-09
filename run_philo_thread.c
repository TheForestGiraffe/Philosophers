/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:47:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/09 02:36:19 by pecavalc         ###   ########.fr       */
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

int	philo_eat_sleep_think(t_philo *philo)
{
	if (philo_eat(philo))
		return (1);
	if (philo_sleep(philo))
		return (1);
	if (philo_think(philo))
		return (1);
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
		return ((void *)1);
	if (set_last_meal_time(philo))
		return ((void *)1);
	if ((philo->id % 2) == 0)
		if (feedback_based_usleep(philo->app->time_to_die / 4, philo->app))
			return ((void *)1);
	if (set_nbr_threads_running_plus_plus(philo->app))
		return ((void *)1);
	while (1)
	{
		if (get_has_simulation_ended(philo->app, &simulation_ended))
			return ((void *)1);
		if (get_has_reached_limit_nbr_meals(philo, &has_reach_limit_nbr_meals))
			return ((void *)1);
		if (simulation_ended || has_reach_limit_nbr_meals)
			break ;
		if (philo_eat_sleep_think(philo))
			return ((void *)1);
	}
	return (NULL);
}
