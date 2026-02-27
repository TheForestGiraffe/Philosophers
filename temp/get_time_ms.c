/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:49:42 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/26 15:13:30 by pecavalc         ###   ########.fr       */
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
