/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:28:15 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/02 10:14:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

static t_fork	*forks_create(long nbr_philos)
{
	t_fork	*forks;
	int		i;

	forks = malloc(sizeof(t_fork) * (size_t)nbr_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nbr_philos)
	{
		if (pthread_mutex_init(&forks[i].fork_mutex, NULL))
			return (NULL);
		forks[i].fork_id = i;
		i++;
	}
	return (forks);
}

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
	t_philo	*philos;
	int		i;

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
		assign_forks(i, app->philos, app->forks, app->nbr_philos);
	}
	return (philos);
}

int	app_setup(int argc, char **argv, t_app_data *app)
{
	if (parse_input(argc, argv, app))
		return (1);
	app->forks = forks_create(app->nbr_philos);
	if (!app->forks)
		return (2);
	app->philos = philos_create(app);
	if (!app->philos)
		return (3);
	return (0);
}
