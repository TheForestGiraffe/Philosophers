/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:28:15 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/01 00:42:31 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
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
