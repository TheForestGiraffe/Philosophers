/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:28:15 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 21:23:01 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

static void	philos_destroy(t_app_data *app)
{
	long	i;

	if (!app || !app->philos)
		return ;
	i = 0;
	while (i < app->nbr_philos)
		pthread_mutex_destroy(&app->philos[i++].philo_mutex);
	free(app->philos);
	app->philos = NULL;
}

void	forks_destroy(t_app_data *app)
{
	long	i;

	if (!app || app->forks)
		return ;
	i = 0;
	while (i < app->nbr_philos)
		pthread_mutex_destroy(&app->forks[i++].fork_mutex);
	free(app->forks);
	app->forks = NULL;
}

void	app_destroy(t_app_data *app)
{
	pthread_mutex_destroy(&app->app_mutex);
	pthread_mutex_destroy(&app->print_mutex);
	forks_destroy(app);
	philos_destroy(app);
	free(app);
}
