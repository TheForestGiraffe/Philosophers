/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_parse_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:39:13 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/28 16:04:40 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	validate_and_parse_input(int argc, char **argv, t_app_data *app)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	if (ft_strtol(argv[1], &app->nbr_philos)
		|| ft_strtol(argv[2], &app->time_to_die)
		|| ft_strtol(argv[3], &app->time_to_eat)
		|| ft_strtol(argv[4], &app->time_to_sleep))
	{
		printf("One or more arguments are invalid\n");
		return (1);
	}
	if (argc == 5)
			app->has_limit_nbr_meals = false;
	if (argc == 6)
	{
		app->has_limit_nbr_meals = true;
		if (ft_strtol(argv[5], &app->limit_nbr_meals))
		{
			printf("philo: one or more arguments are invalid\n");
			return (1);
		}
	}
	return (0);
}
