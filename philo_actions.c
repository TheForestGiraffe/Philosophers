/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:31:48 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 20:42:10 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	// Take (lock) forks
	if (pthread_mutex_lock(&philo->first_fork->fork_mutex))
		return (1);
	if (thread_safe_printf(TOOK_FIRST_FORK, philo))
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

int	philo_sleep(t_philo *philo)
{
	if (thread_safe_printf(IS_SLEEPING, philo))
		return (1);
	if (feedback_based_usleep(philo->app->time_to_sleep * 1000L, philo->app))
		return (1);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (thread_safe_printf(IS_THINKING, philo))
		return (1);
	return (0);
}