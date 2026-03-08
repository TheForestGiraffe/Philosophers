/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_get_and_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:30:59 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/08 20:15:49 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_has_simulation_ended(t_app_data *app, bool *out)
{
	int	rc;

	rc = pthread_mutex_lock(&app->app_mutex);
	if (rc)
		return (rc);
	*out = app->has_simulation_ended;
	rc = pthread_mutex_unlock(&app->app_mutex);
	if (rc)
		return (rc);
	return (0);
}

int	set_simulation_ended_and_all_threads_ready(t_app_data *app)
{
	if (pthread_mutex_lock(&app->app_mutex))
		return (1);
	app->has_simulation_ended = true;
	app->all_threads_ready = true;
	if (pthread_mutex_unlock(&app->app_mutex))
		return (1);
	return (0);
}

int	set_all_threads_ready(t_app_data *app)
{
	if (pthread_mutex_lock(&app->app_mutex))
		return (1);
	app->all_threads_ready = true;
	if (pthread_mutex_unlock(&app->app_mutex))
		return (1);
	return (0);
}