/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:47:51 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 20:21:11 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <pthread.h>

static int	philo_eat(t_philo *philo)
{
	// Take (lock) forks
	if (pthread_mutex_lock(&philo->first_fork->fork_mutex))
		return (1);
	if (f(TOOK_FIRST_FORK, philo))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		return (1);
	}
	if (pthread_mutex_lock(&philo->second_fork->fork_mutex))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		return (1);
	}
	if (thread_safe_printf(TOOK_SECOND_FORK, philo))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
		return (1);
	}

	// Eat
	if (pthread_mutex_lock(&philo->philo_mutex))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
		return (1);
	}
	philo->last_meal_time = get_time_ms();
	if (pthread_mutex_unlock(&philo->philo_mutex))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
		return (1);
	}		
	if (thread_safe_printf(IS_EATING, philo))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
		return (1);
	}
	if (feedback_based_usleep(philo->app->time_to_eat * 1000L, philo->app))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
		return (1);
	}
	if (pthread_mutex_lock(&philo->philo_mutex))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
		return (1);
	}
	philo->meals_counter++;
	if (philo->app->limit_nbr_meals > 0
		&& philo->meals_counter >= philo->app->limit_nbr_meals)
		philo->has_reached_limit_nbr_meals = true;
	if (pthread_mutex_unlock(&philo->philo_mutex))
	{
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
		return (1);
	}
	
	// Release (unlock) forks
	if (pthread_mutex_unlock(&philo->first_fork->fork_mutex))
	{
		pthread_mutex_unlock(&philo->second_fork->fork_mutex);
		return (1);
	}
	if (pthread_mutex_unlock(&philo->second_fork->fork_mutex))
		return (1);
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	if (thread_safe_printf(IS_SLEEPING, philo))
		return (1);
	if (feedback_based_usleep(philo->app->time_to_sleep * 1000L, philo->app))
		return (1);
	return (0);
}

static int	philo_think(t_philo *philo)
{
	if (thread_safe_printf(IS_THINKING, philo))
		return (1);
	return (0);
}

static int	get_has_reached_limit_nbr_meals(t_philo *philo, bool *out)
{
	if (pthread_mutex_lock(&philo->philo_mutex))
		return (1);
	*out = philo->has_reached_limit_nbr_meals;
	if (pthread_mutex_unlock(&philo->philo_mutex))
		return (1);
	return (0);
}

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
	
	// Set last meal time
	if (pthread_mutex_lock(&philo->philo_mutex))
		return (NULL);
	philo->last_meal_time = get_time_ms();
	if (pthread_mutex_unlock(&philo->philo_mutex))
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

