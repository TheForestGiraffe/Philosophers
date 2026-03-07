/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:28:15 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 21:22:26 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

static void	assign_forks(int i, t_philo *philos, t_fork *forks, long nbr_philos)
{
	if ((i % 2) == 0)
	{
		philos[i].first_fork = &forks[i];
		philos[i].second_fork = &forks[(i + 1) % nbr_philos];
	}
	else
	{
		philos[i].first_fork = &forks[(i + 1) % nbr_philos];
		philos[i].second_fork = &forks[i];
	}
}

static t_philo	*philos_create(t_app_data *app)
{
	int		rc;
	t_philo	*philos;
	long	i;

	philos = malloc(sizeof(t_philo) * (size_t)app->nbr_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < app->nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_counter = 0;
		philos[i].has_reached_limit_nbr_meals = false;
		philos[i].last_meal_time = -1;
		philos[i].app = app;
		assign_forks(i, philos, app->forks, app->nbr_philos);
		rc = pthread_mutex_init(&philos[i].philo_mutex, NULL);
		if (rc)
		{
			while (i > 0)
				pthread_mutex_destroy(&philos[--i].philo_mutex);
			free(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}

static t_fork	*forks_create(long nbr_philos)
{
	t_fork	*forks;
	long	i;

	forks = malloc(sizeof(t_fork) * (size_t)nbr_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nbr_philos)
	{
		if (pthread_mutex_init(&forks[i].fork_mutex, NULL))
		{
			while (i > 0)
				pthread_mutex_destroy(&forks[--i].fork_mutex);
			free(forks);
			return (NULL);
		}
		forks[i].fork_id = (int)i;
		i++;
	}
	return (forks);
}

static int	app_init(t_app_data *app)
{
	int	rc;

	app->minimum_time_allowed = 60;
	app->has_limit_nbr_meals = false;
	app->limit_nbr_meals = 0;
	app->has_simulation_ended = false;
	app->philos = NULL;
	app->forks = NULL;
	app->all_threads_ready = false;
	app->nbr_threads_running = 0;
	rc = pthread_mutex_init(&app->app_mutex, NULL);
	if (rc)
		return (rc);
	rc = pthread_mutex_init(&app->print_mutex, NULL);
	if (rc)
	{
		pthread_mutex_destroy(&app->app_mutex);
		return (rc);
	}
	return (0);
}

t_app_data	*app_create(int argc, char **argv)
{
	int			rc;
	t_app_data	*app;

	app = malloc(sizeof(t_app_data));
	if (!app)
		return (NULL);
	rc = app_init(app);
	if (rc)
	{
		free(app);
		return (NULL);
	}
	rc = parse_input(argc, argv, app);
	if (rc)
	{
		pthread_mutex_destroy(&app->app_mutex);
		pthread_mutex_destroy(&app->print_mutex);
		free(app);
		return (NULL);
	}
	app->forks = forks_create(app->nbr_philos);
	if (!app->forks)
	{
		pthread_mutex_destroy(&app->app_mutex);
		pthread_mutex_destroy(&app->print_mutex);
		free(app);
		return (NULL);
	}
	app->philos = philos_create(app);
	if (!app->philos)
	{
		pthread_mutex_destroy(&app->app_mutex);
		pthread_mutex_destroy(&app->print_mutex);
		forks_destroy(app);
		free(app);
		return (NULL);
	}
	return (app);
}
