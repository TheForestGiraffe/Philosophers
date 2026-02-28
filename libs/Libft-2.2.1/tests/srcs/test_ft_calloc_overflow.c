/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc_overflow.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:42:01 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/15 22:59:10 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "libft.h"

int	test_ft_calloc_overflow(void)
{
	size_t			nmemb;
	size_t			size;
	unsigned char	*array;

	nmemb = (SIZE_MAX / 2) + 1;
	size = 2 * sizeof(char);
	array = (unsigned char *)ft_calloc(nmemb, size);
	if (array != NULL)
		return (0);
	return (1);
}
