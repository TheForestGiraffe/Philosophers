/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2025/12/03 21:14:29 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t	mutex;

void	*live()
{
	
	return (NULL);
}

int main(int argc, char **argv)
{
	pthread_t	*t_array;
	
	pthread_init_mutex(&mutex, NULL);

	parse_input(argv);

	pthread_destroy_mutex(&mutex, NULL);

	return (0);
}
