/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:22:43 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/20 12:02:45 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	test_ft_split(void)
{
	char	str[] = "    Lorem ipsum dolor, sit .  ";
	char	**str_array;
	int		i;
	int		test_result;

	test_result = 1;
	str_array = ft_split(str, ' ');
	//printf("str_array[0]: %s\n", str_array[0]);
	//printf("str_array[1]: %s\n", str_array[1]);
	//printf("str_array[2]: %s\n", str_array[2]);
	//printf("str_array[3]: %s\n", str_array[3]);
	//printf("str_array[4]: %s\n", str_array[4]);

	if (strncmp(str_array[0], "Lorem", 5) != 0)
		test_result = 0;
	if (strncmp(str_array[1], "ipsum", 5) != 0)
		test_result = 0;
	if (strncmp(str_array[2], "dolor,", 5) != 0)
		test_result = 0;
	if (strncmp(str_array[3], "sit", 3) != 0)
		test_result = 0;
	if (strncmp(str_array[4], ".", 1) != 0)
		test_result = 0;

	// Free memory
	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
	return (test_result);
}