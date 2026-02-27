/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:14:47 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/27 13:22:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
	int				fork_id;
}					t_fork;

// WIP
typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		has_reached_max_meals;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;

}				t_philo;


#endif
