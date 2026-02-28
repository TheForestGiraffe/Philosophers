/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:39:13 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/28 22:30:55 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

static int	convert_and_validate_first_arguments(char **argv, t_app_data *app)
{
	if (ft_strtol(argv[1], &app->nbr_philos)
		|| ft_strtol(argv[2], &app->time_to_die)
		|| ft_strtol(argv[3], &app->time_to_eat)
		|| ft_strtol(argv[4], &app->time_to_sleep))
	{
		printf("One or more arguments are invalid.\n");
		return (1);
	}
	if (app->nbr_philos < 2)
	{
		printf("The number of philosophers must be at least 2.");
		return (1);
	}
	if (app->time_to_die < app->minimum_time_allowed
		|| app->time_to_eat < app->minimum_time_allowed
		|| app->time_to_sleep < app->minimum_time_allowed)
	{
		printf("The minimum time allowed is %ld ms.\n", app->minimum_time_allowed);
		return (1);
	}
	return (0);
}

int	parse_input(int argc, char **argv, t_app_data *app)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	if (convert_and_validate_first_arguments(argv, app))
		return (1);
	if (argc == 6)
	{
		app->has_limit_nbr_meals = true;
		if (ft_strtol(argv[5], &app->limit_nbr_meals)
			|| app->limit_nbr_meals < 1)
		{
			printf("The optional argument is invalid.\n");
			return (1);
		}
	}
	return (0);
}
