/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:42:17 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/09 17:49:52 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	print_str(const char *str)
{
	int	n_chars;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	n_chars = 0;
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		n_chars++;
	}
	return (n_chars);
}
