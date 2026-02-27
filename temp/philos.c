/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:12:52 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/26 20:27:13 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h" 

t_philo	*philos_create(const long nr_philos)
{
	t_philo	*philos;

	if (nr_philos < 1)
		return (NULL);
	philos = malloc(sizeof(t_philo) * (size_t)nr_philos);
	if (!philos)
		return (NULL);
	return (philos);
}

void	philos_set_time_last_meal(long start_time, long nr_philos, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < nr_philos)
		philos[i++]->last_meal = start_time;
}


