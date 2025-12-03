/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:14:47 by pecavalc          #+#    #+#             */
/*   Updated: 2025/12/03 23:17:01 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_data {
	long		nr_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nr_times_each_must_eat;
}				t_data;

int	parse(int argc, char **argv, t_data *data);
int	ft_strtol(const char *str, long *number);

#endif