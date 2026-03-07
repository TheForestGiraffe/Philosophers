/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:08:21 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 14:33:17 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	thread_safe_print(t_philo_status philo_status, t_philo *philo)
{
	int	rc;

	rc = pthread_mutex_lock(&philo->app->print_mutex);
	if (rc)
		return (rc);
	if (philo_status == IS_EATING)
	{

	}
	if (philo_status == IS_SLEEPING)
	{
		//TODO
	}
	if (philo_status == IS_THINKING)
	{

	}
	if (philo_status == TOOK_FIRST_FORK)
	{

	}
	if (philo_status == TOOK_SECOND_FORK)
	{

	}
	if (philo_status == HAS_DIED)
	{

	}

	return (0);
}