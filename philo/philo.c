/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2025/12/03 23:51:46 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *philo_routine(void *nbr)
{
	*(int *)nbr += 1;
	printf("Philo %i\n", *(int *)nbr);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	int			nbr;
	pthread_t	philo_1;
	pthread_t	philo_2;
	pthread_t	philo_3;

	if (parse(argc, argv, &data))
		return (1);
	
	nbr = 2;
	pthread_create(&philo_1, NULL, philo_routine, (void *)&nbr);
	pthread_create(&philo_2, NULL, philo_routine, (void *)&nbr);
	pthread_create(&philo_3, NULL, philo_routine, (void *)&nbr);
	
	pthread_join(philo_1, NULL);
	pthread_join(philo_2, NULL);
	pthread_join(philo_3, NULL);

	return (0);
}
