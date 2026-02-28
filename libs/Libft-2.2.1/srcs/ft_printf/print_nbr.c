/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:42:17 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/09 17:44:42 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	print_nbr(const int n)
{
	long long	digit;
	char		digit_char;
	ssize_t		n_chars;
	ssize_t		print_nbr_return;

	digit = (long long)n;
	n_chars = 0;
	if (n < 0)
	{
		n_chars = write(1, "-", 1);
		if (n_chars == -1)
			return (-1);
		digit *= -1;
	}
	if (digit >= 10)
	{
		print_nbr_return = print_nbr((int)(digit / 10));
		if (print_nbr_return == -1)
			return (-1);
		n_chars += print_nbr_return;
	}
	digit_char = digit % 10 + '0';
	if (write(1, &digit_char, 1) == -1)
		return (-1);
	return (n_chars + 1);
}
