/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:49:42 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/07 12:21:34 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>

long	get_time_ms(void)
{
	struct timeval	tv;
	long			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
	return (time_ms);
}

long	get_time_us(void)
{
	struct timeval	tv;
	long			time_us;

	gettimeofday(&tv, NULL);
	time_us = (tv.tv_sec * 1000000L) + (tv.tv_usec);
	return (time_us);
}

/*	TODO: Preciser usleep function
	It uses usleep for the majority of time, which is not CPU intensive
	And for the last microseconds it uses spinlock, which is CPU intensive */

