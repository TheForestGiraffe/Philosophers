/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:31:48 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/09 00:12:50 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_take_forks(t_philo *philo)
{
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
	return (0);
}

static int	philo_drop_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->first_fork->fork_mutex))
		return (1);
	if (pthread_mutex_unlock(&philo->second_fork->fork_mutex))
		return (1);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	if (philo_take_forks(philo))
		return (1);
	if (set_last_meal_time(philo))
		return (philo_drop_forks(philo), 1);
	if (thread_safe_printf(IS_EATING, philo))
		return (philo_drop_forks(philo), 1);
	if (feedback_based_usleep(philo->app->time_to_eat * 1000L, philo->app))
		return (philo_drop_forks(philo), 1);
	if (pthread_mutex_lock(&philo->philo_mutex))
		return (philo_drop_forks(philo), 1);
	philo->meals_counter++;
	if (philo->app->limit_nbr_meals > 0
		&& philo->meals_counter >= philo->app->limit_nbr_meals)
		philo->has_reached_limit_nbr_meals = true;
	if (pthread_mutex_unlock(&philo->philo_mutex))
		return (philo_drop_forks(philo), 1);
	if (philo_drop_forks(philo))
		return (1);
	return (0);
}
