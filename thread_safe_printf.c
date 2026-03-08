/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:08:21 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 20:25:06 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

static int	print_status(t_philo_status philo_status, long philo_id,
							long elapsed_time)
{
	if (philo_status == IS_EATING)
		printf("%ld %i is eating\n", elapsed_time, philo_id);
	if (philo_status == IS_SLEEPING)
		printf("%ld %i is sleeping\n", elapsed_time, philo_id);
	if (philo_status == IS_THINKING)
		printf("%ld %i is thinking\n", elapsed_time, philo_id);
	if (philo_status == TOOK_FIRST_FORK || philo_status == TOOK_SECOND_FORK)
		printf("%ld %i has taken a fork\n", elapsed_time, philo_id);
	if (philo_status == HAS_DIED)
		printf("%ld %i died\n", elapsed_time, philo_id);

}

int	thread_safe_printf(t_philo_status philo_status, t_philo *philo)
{
	long	elapsed_time;
	bool	simulation_ended;

	elapsed_time = get_time_ms() - philo->app->simulation_start_time;
	if (pthread_mutex_lock(&philo->app->print_mutex))
		return (1);
	if (get_has_simulation_ended(philo->app, &simulation_ended))
	{
		pthread_mutex_unlock(&philo->app->print_mutex);
		return (1);
	}
	if (simulation_ended)
	{
		if (pthread_mutex_unlock(&philo->app->print_mutex))
			return (1);
		return (0);
	}
	if (print_status(philo_status, philo->id, elapsed_time))
		return (1);
	if (pthread_mutex_unlock(&philo->app->print_mutex))
		return (1);
	return (0);
}
