/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:31:48 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/09 00:59:53 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	philo_think(t_philo *philo)
{
	long	think_time_us;

	if (thread_safe_printf(IS_THINKING, philo))
		return (1);
	think_time_us = (((philo->app->time_to_eat * 2)
				- philo->app->time_to_sleep) * 1000L) / 2;
	if (think_time_us > 0)
		if (feedback_based_usleep(think_time_us, philo->app))
			return (1);
	return (0);
}
