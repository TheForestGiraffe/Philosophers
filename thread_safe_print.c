/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:08:21 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 21:53:39 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	thread_safe_print(t_philo_status philo_status, t_philo *philo)
{
	int		rc;
	long	elapsed_time;
	bool	simulation_ended;

	rc = pthread_mutex_lock(&philo->app->print_mutex);
	if (rc)
		return (rc);
	elapsed_time = get_time_ms() - philo->app->simulation_start_time;
	rc = get_has_simulation_ended(philo->app, &simulation_ended);
	if (rc)
	{
		rc = pthread_mutex_unlock(&philo->app->print_mutex);
		return (rc);
	}
	if (simulation_ended)
	{
		rc = pthread_mutex_unlock(&philo->app->print_mutex);
		return (0);
	}
	if (philo_status == IS_EATING)
		printf("%ld %i is eating\n", elapsed_time, philo->id);
	if (philo_status == IS_SLEEPING)
		printf("%ld %i is sleeping\n", elapsed_time, philo->id);
	if (philo_status == IS_THINKING)
		printf("%ld %i is thinking\n", elapsed_time, philo->id);
	if (philo_status == TOOK_FIRST_FORK || philo_status == TOOK_SECOND_FORK)
		printf("%ld %i has taken a fork\n", elapsed_time, philo->id);
	if (philo_status == HAS_DIED)
		printf("%ld %i died\n", elapsed_time, philo->id);
	rc = pthread_mutex_unlock(&philo->app->print_mutex);
	return (rc);
}
