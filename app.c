/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:30:59 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 13:31:38 by pecavalc         ###   ########.fr       */
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