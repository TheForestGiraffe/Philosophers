/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:42:17 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/09 17:50:16 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	print_unsigned_nbr(const unsigned int n)
{
	char	digit_char;
	ssize_t	n_chars;
	ssize_t	print_unbr_return;

	n_chars = 0;
	if (n >= 10)
	{
		print_unbr_return = print_unsigned_nbr(n / 10);
		if (print_unbr_return == -1)
			return (-1);
		n_chars += print_unbr_return;
	}
	digit_char = n % 10 + '0';
	if (write(1, &digit_char, 1) == -1)
		return (-1);
	return (n_chars + 1);
}
