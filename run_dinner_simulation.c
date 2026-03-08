/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_dinner_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:17:49 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/09 00:23:09 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

/* 	Joins the threads and verifies if any thread returned 1 for error.
	The return valur is encoded in the value of the returned pointer. That is
	why casting (int)(lont)ret is done. An error is returned from a trhead in 
	the following way: return ((void *)1) */

static int	join_philo_threads(t_app_data *app)
{
	long	i;
	void	*thread_rc;
	int		error;

	i = 0;
	error = 0;
	while (i < app->nbr_philos)
	{
		if (pthread_join(app->philos[i++].thread_id, &thread_rc))
			error = 1;
		if ((int)(long)thread_rc == 1)
			error = 1;
	}
	return (error);
}

static int	join_all_threads(t_app_data *app)
{
	void	*thread_rc;
	int		rc;

	rc = 0;
	if (pthread_join(app->monitor, &thread_rc))
		rc = 1;
	if ((int)(long)thread_rc == 1)
		rc = 1;
	if (join_philo_threads(app))
		rc = 1;
	return (rc);
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
		join_philo_threads(app);
		return (1);
	}
	app->simulation_start_time = get_time_ms();
	if (set_all_threads_ready(app))
	{
		set_simulation_ended_and_all_threads_ready(app);
		join_all_threads(app);
		return (1);
	}
	if (join_all_threads(app))
		return (1);
	return (0);
}
