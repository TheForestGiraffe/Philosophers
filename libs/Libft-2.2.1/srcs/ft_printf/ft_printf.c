/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:42:17 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/06 17:22:58 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	ssize_t	len;
	ssize_t	n_chars;
	va_list	args;

	if (!str)
		return (-1);
	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			n_chars = print_char(*str);
		else if (*(str + 1) == '%')
			n_chars = print_char(*str++);
		else
			n_chars = convert_arg(&str, &args);
		if (n_chars < 0)
			return (-1);
		len += n_chars;
		str++;
	}
	va_end(args);
	if (len <= INT_MAX)
		return ((int)len);
	return (-1); 
}
