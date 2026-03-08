/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:49:42 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 19:37:44 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;
	long			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
	return (time_ms);
}

long	get_time_us(void)
{
	struct timeval	tv;
	long			time_us;

	gettimeofday(&tv, NULL);
	time_us = (tv.tv_sec * 1000000L) + (tv.tv_usec);
	return (time_us);
}

int	feedback_based_usleep(long sleep_time_us, t_app_data *app)
{
	long	start_time;
	long	elapsed_time;
	long	remaining_time;
	bool	simulation_ended;

	start_time = get_time_us();
	while (1)
	{
		if (get_has_simulation_ended(app, &simulation_ended))
			return (1);
		if (simulation_ended)
			break ;
		elapsed_time = get_time_us() - start_time; 
		if (elapsed_time >= sleep_time_us)
			break ;
		remaining_time = sleep_time_us - elapsed_time;
		if (remaining_time > 500)
			usleep(remaining_time / 2);
		else
			while ((get_time_us() - start_time) <= sleep_time_us)
				;
	}
	return (0);
}
