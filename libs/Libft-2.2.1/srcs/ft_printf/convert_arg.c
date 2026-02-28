/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:44:47 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/06 17:22:53 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

ssize_t	convert_arg(const char **str, va_list *args)
{
	ssize_t	n_chars;

	n_chars = 0;
	(*str)++;
	if (**str == 'c')
		n_chars = print_char(va_arg(*args, int));
	if (**str == 's')
		n_chars = print_str(va_arg(*args, char *));
	if (**str == 'd')
		n_chars = print_nbr(va_arg(*args, int));
	if (**str == 'i')
		n_chars = print_nbr(va_arg(*args, int));
	if (**str == 'u')
		n_chars = print_unsigned_nbr(va_arg(*args, unsigned int));
	if (**str == 'x')
		n_chars = print_hex_lowcase_nbr(va_arg(*args, unsigned int));
	if (**str == 'X')
		n_chars = print_hex_uppercase_nbr(va_arg(*args, unsigned int));
	if (**str == 'p')
		n_chars = prefix_and_print_ptr(va_arg(*args, void *));
	return (n_chars);
}
