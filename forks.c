/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:12:52 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/26 11:44:28 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>

/* forks_create owns *forks and transfers ownership on return */

pthread_mutex_t	*forks_create(const long nr_philos)
{
	pthread_mutex_t	*forks;
	int				i;

	if (nr_philos < 1)
		return (NULL);

	forks = malloc(sizeof(pthread_mutex_t) * (size_t)nr_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nr_philos)
	{
		if (pthread_mutex_init(&(forks[i]), NULL) != 0)
		{
			forks_destroy(i, &forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

/* forks_destroy destroys and frees an array created by forks_create.
 * Safe to call with NULL or *forks == NULL.*/

void	forks_destroy(const long nr_forks_to_destroy, pthread_mutex_t **forks)
{
	int	i;

	if (!forks || !*forks)
		return ;
	i = 0;
	while (i < nr_forks_to_destroy)
		pthread_mutex_destroy(&(*forks)[i++]);
	free(*forks);
	*forks = NULL;
}
