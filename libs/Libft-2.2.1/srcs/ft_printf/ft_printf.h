/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:04:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/06 17:15:47 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include <unistd.h>

ssize_t	convert_arg(const char **str, va_list *args);
ssize_t	print_char(const int c);
ssize_t	print_str(const char *str);
ssize_t	print_nbr(const int n);
ssize_t	print_unsigned_nbr(const unsigned int n);
ssize_t	print_hex_lowcase_nbr(const unsigned int n);
ssize_t	print_hex_uppercase_nbr(const unsigned int n);
ssize_t	prefix_and_print_ptr(const void *ptr);

#endif