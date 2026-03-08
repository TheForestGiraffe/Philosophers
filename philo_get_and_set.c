/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get_and_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:27:56 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 20:35:28 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_has_reached_limit_nbr_meals(t_philo *philo, bool *out)
{
	if (pthread_mutex_lock(&philo->philo_mutex))
		return (1);
	*out = philo->has_reached_limit_nbr_meals;
	if (pthread_mutex_unlock(&philo->philo_mutex))
		return (1);
	return (0);
}

int	set_last_meal_time(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->philo_mutex))
		return (1);
	philo->last_meal_time = get_time_ms();
	if (pthread_mutex_unlock(&philo->philo_mutex))
		return (1);
	return (0);
}
