/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/26 20:34:21 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data			data;

	data_init(&data);

	if (parse(argc, argv, &data))
		return (1);

	data.philos = philos_create(data.nr_philos);
	if (!data.philos)
	{
		destroy_data(&data);
		return (1);
	}
	data.start_time = get_time_ms();
	philos_set_time_last_meal(data.start_time);
	if(philos_start_routines(data.philo_threads))


	// how to monitor routines?

	// cleanup

	//pthread_create(&philo_1, NULL, philo_routine, (void *)&nbr);
	//pthread_join(philo_1, NULL);
	return (0);
}
