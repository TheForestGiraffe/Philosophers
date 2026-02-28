/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_uppercase_nbr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:42:17 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/09 17:44:24 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	print_hex_uppercase_nbr(const unsigned int n)
{
	char	*base;
	char	digit_char;
	ssize_t	n_chars;

	base = "0123456789ABCDEF";
	n_chars = 0;
	if (n >= 16)
	{
		n_chars = print_hex_uppercase_nbr(n / 16);
		if (n_chars == -1)
			return (-1);
	}
	digit_char = base[n % 16];
	if (write(1, &digit_char, 1) == -1)
		return (-1);
	return (n_chars + 1);
}
