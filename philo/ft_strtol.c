/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:21:03 by pecavalc          #+#    #+#             */
/*   Updated: 2025/12/03 23:46:09 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>

static int	validate_first_characters(const char *str, int *sign, int *i)
{
	if (str[0] == '\0')
		return (1);
	*sign = 1;
	*i = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		else
			*sign = 1;
		(*i)++;
	}
	if (str[*i] < '0' || str[*i] > '9')
		return (2);
	return (0);
}

static unsigned long	max_number(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	else
		return (-(unsigned long)LONG_MIN);
}

int	ft_strtol(const char *str, long *number)
{
	int				i;
	int				sign;
	int				digit;
	unsigned long	result;

	if (!str)
		return (1);
	if (validate_first_characters(str, &sign, &i))
		return (2);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i++] - '0';
		if (result > (max_number(sign) - digit) / 10)
			return (3);
		result = result * 10 + digit;
	}
	if (str[i] != '\0')
		return (4);
	*number = (long)result * sign;
	return (0);
}
