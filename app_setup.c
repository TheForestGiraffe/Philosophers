/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:28:15 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/01 01:18:17 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

static int	fork_array_setup(t_app_data *app)
{
	int	i;
	
	app->fork_array = malloc(sizeof(t_fork) * (size_t)app->nbr_philos);
	if (!app->fork_array)
		return (1);
	i = 0;
	while (i < app->nbr_philos)
	{
		if (pthread_mutex_init(&app->fork_array[i].fork_mutex, NULL))
			return (2);
		app->fork_array[i].fork_id = i;
		i++;
	}
	return (0);
}

static void assign_forks(t_philo *philo_array, t_fork *fork_array,
	int nbr_philos, int i)
{
	if ((i % 2) == 0)
	{
		philo_array[i].right_fork = &fork_array[i];
		philo_array[i].left_fork = &fork_array[(i + 1) % nbr_philos];
	}
	else
	{
		philo_array[i].left_fork = &fork_array[i];
		philo_array[i].right_fork = &fork_array[(i + 1) % nbr_philos];
	}
}

static int	philo_array_setup(t_app_data *app)
{
	int	i;

	app->philo_array = malloc(sizeof(t_philo) * (size_t)app->nbr_philos);
	if (!app->philo_array)
		return (1);
	i = 0;
	while (i < app->nbr_philos)
	{
		app->philo_array[i].id = i + 1;
		app->philo_array[i].meals_counter = 0;
		app->philo_array[i].has_reached_limit_nbr_meals = false;
		app->philo_array[i].last_meal_time = -1;
		app->philo_array[i].app = app;
		assign_forks(app->philo_array, app->fork_array, app->nbr_philos, i);
		i++;
	}
	return (0);
}

int	app_setup(int argc, char **argv, t_app_data *app)
{
	if (parse_input(argc, argv, app))
		return (1);
	if (fork_array_setup(app))
		return (2);	
	if (philo_array_setup(app))
		return (3);
	return (0);
}
