/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:42:01 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/18 22:28:23 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "libft.h"

int	test_ft_calloc(void)
{
	size_t			i;
	size_t			nmemb;
	size_t			size;
	unsigned char	*array;

	nmemb = 500;
	size = 100 * sizeof(char);
	array = (unsigned char *)ft_calloc(nmemb, size);
	if (array == NULL)
	{
		printf("test_ft_calloc: memory could not be allocated for the test.\n");
		return (0);
	}
	i = 0;
	while (i < nmemb * size)
	{
		if (array[i] == '\0')
			i++;
		else
		{
			free(array);
			return (0);
		} 
	}
	free(array);
	return (1);
}
