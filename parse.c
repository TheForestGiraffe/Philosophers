/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:39:13 by pecavalc          #+#    #+#             */
/*   Updated: 2025/12/03 23:49:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	parse(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		printf("philo: invalid number of arguments\n");
		return (1);
	}
	if (ft_strtol(argv[1], &data->nr_philos)
		|| ft_strtol(argv[2], &data->time_to_die)
		|| ft_strtol(argv[3], &data->time_to_eat)
		|| ft_strtol(argv[4], &data->time_to_sleep))
	{
		printf("philo: one or more arguments are invalid\n");
		return (1);
	}
	if (argc == 5)
		data->nr_times_each_must_eat = 0;
	if (argc == 6)
	{
		if (ft_strtol(argv[5], &data->nr_times_each_must_eat))
		{
			printf("philo: one or more arguments are invalid\n");
			return (1);
		}
	}
	return (0);
}
