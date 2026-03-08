/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_dinner_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:17:49 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 19:44:01 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

static int	join_philo_threads(t_app_data *app, long count)
{
	long	i;

	i = 0;
	while (i < count)
		if (pthread_join(app->philos[i++].thread_id, NULL))
			return (1);
	return (0);
}

static int	create_philo_threads(t_app_data *app)
{
	long	i;
	long	j;

	i = 0;
	while (i < app->nbr_philos)
	{
		if (pthread_create(&app->philos[i].thread_id, NULL,
				run_philo_thread, (void *)&app->philos[i]))
		{
			set_simulation_ended_and_all_threads_ready(app);
			j = 0;
			while (j < i)
				pthread_join(app->philos[j++].thread_id, NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	set_all_threads_ready(t_app_data *app)
{
	if (pthread_mutex_lock(&app->app_mutex))
		return (1);
	app->all_threads_ready = true;
	if (pthread_mutex_unlock(&app->app_mutex))
		return (1);
	return (0);
}

int	run_dinner_simulation(t_app_data *app)
{
	if (app->nbr_philos == 1)
	{
		printf("0 1 has taken a fork\n%ld 1 died\n", app->time_to_die);
		return (0);
	}
	if (create_philo_threads(app))
		return (1);
	if (pthread_create(&app->monitor, NULL, run_monitor_thread, app))
	{
		set_simulation_ended_and_all_threads_ready(app);
		join_philo_threads(app, app->nbr_philos);
		return (1);
	}
	app->simulation_start_time = get_time_ms();
	if (set_all_threads_ready(app))
	{
		set_simulation_ended_and_all_threads_ready(app);
		pthread_join(app->monitor, NULL);
		join_philo_threads(app, app->nbr_philos);
		return (1);
	}
	if (pthread_join(app->monitor, NULL)
		|| join_philo_threads(app, app->nbr_philos))
		return (1);
	return (0);
}
