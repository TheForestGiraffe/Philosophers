/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:25:26 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/20 14:12:11 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	get_length(int n);
static char		*nbr_to_str(int n, char *str, size_t length);

char	*ft_itoa(int n)
{
	size_t		length;
	char		*str;

	length = get_length(n);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	nbr_to_str(n, str, length);
	return (str);
}

size_t	get_length(int n)
{
	signed long	n_copy;
	size_t		length;

	if (n == 0)
		return (1);
	n_copy = (signed long)n;
	length = 0;
	if (n_copy < 0)
	{
		n_copy *= -1;
		length++;
	}
	while (n_copy > 0)
	{
		n_copy /= 10;
		length++;
	}
	return (length);
}

char	*nbr_to_str(int n, char *str, size_t length)
{
	signed long	n_copy;
	size_t		i;
	size_t		i_min;

	n_copy = (signed long)n;
	i_min = 1;
	if (n_copy < 0)
	{
		n_copy *= -1;
		str[0] = '-';
		i_min = 2;
	}
	i = length;
	while (i >= i_min)
	{
		i--;
		str[i] = n_copy % 10 + '0';
		n_copy /= 10;
	}
	str[length] = '\0';
	return (str);
}
