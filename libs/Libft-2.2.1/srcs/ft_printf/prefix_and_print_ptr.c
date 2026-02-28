/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_and_print_ptr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:42:17 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/09 21:38:10 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

static ssize_t	print_ptr(const uintptr_t n);

ssize_t	prefix_and_print_ptr(const void *ptr)
{
	ssize_t	n_chars_prefix;
	ssize_t	n_chars_print_ptr;

	if (!ptr)
		return (write(1, "(nil)", 5));
	n_chars_prefix = write(1, "0x", 2);
	if (n_chars_prefix == -1)
		return (-1);
	n_chars_print_ptr = print_ptr((uintptr_t)ptr);
	if (n_chars_print_ptr == -1)
		return (-1);
	return (n_chars_prefix + n_chars_print_ptr);
}

static ssize_t	print_ptr(const uintptr_t n)
{
	char	*base;
	char	digit_char;
	ssize_t	n_chars;

	base = "0123456789abcdef";
	n_chars = 0;
	if (n >= 16)
	{
		n_chars += print_ptr(n / 16);
		if (n_chars == -1)
			return (-1);
	}
	digit_char = base[n % 16];
	if (write(1, &digit_char, 1) == -1)
		return (-1);
	return (n_chars + 1);
}
