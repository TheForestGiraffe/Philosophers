/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:28:15 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/01 00:19:45 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "philo.h"

void app_init(t_app_data *app)
{
	app->nbr_philos = 0;
	app->minimum_time_allowed = 60;
	app->time_to_die = 0;
	app->time_to_eat = 0;
	app->time_to_sleep = 0;
	app->has_limit_nbr_meals = false;
	app->limit_nbr_meals = 0;
	app->simulation_start_time = 0;
	app->stop_simulation_flag = false;
	app->philo_array = NULL;
	app->fork_array = NULL;
}

int	fork_array_setup(t_app_data *app)
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

int	philo_array_setup(t_app_data *app)
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
		// TODO: assign forks
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

void	app_destroy(t_app_data *app)
{
	app->nbr_philos = 1;
	// TODO
}
