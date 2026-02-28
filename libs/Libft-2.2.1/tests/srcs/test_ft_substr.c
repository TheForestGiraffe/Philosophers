/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:29:06 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/22 15:43:39 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	test_ft_substr(void)
{
	char	str_1[] = "Lorem Ipsum.";
	char	str_2[] = "test";
	char	*substr_1;
	char	*substr_2;
	char	*substr_3;

	substr_1 = ft_substr(str_1, 6, 5);
	substr_2 = ft_substr(str_2, 10, 1);
	substr_3 = ft_substr(str_2, 2, 0);
	//printf("str_1: %s\n", str_1);
	//printf("substr: %s\n", substr);
	if (strncmp("Ipsum", substr_1, 6) != 0)
		return (0);
	// test if return is null when provided leng is larger than s len.
	if (strncmp("", substr_2, 10) != 0)
		return (0);
	// test if return is null when len = 0.
	if (strncmp("", substr_3, 10) != 0)
		return (0);
	free(substr_1);
	free(substr_2);
	free(substr_3);
	return (1);
}
