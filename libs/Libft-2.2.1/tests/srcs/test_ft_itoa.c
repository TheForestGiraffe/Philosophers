/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:44:08 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/20 14:13:55 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

int	test_ft_itoa(void)
{
	int		test_result;
	int		n_0;
	int		n_1;
	int		n_2;
	int		n_3;
	int		n_4;
	char	*s_0;
	char	*s_1;
	char	*s_2;
	char	*s_3;
	char	*s_4;

	test_result = 1;
	n_0 = 0;
	n_1 = -42;
	n_2 = 42;
	n_3 = INT_MIN;
	n_4 = INT_MAX;
	s_0 = ft_itoa(n_0);
	s_1 = ft_itoa(n_1);
	s_2 = ft_itoa(n_2);
	s_3 = ft_itoa(n_3);
	s_4 = ft_itoa(n_4);
	/*
	printf("n: %i, s: %s\n", n_0, s_0);
	printf("n: %i, s: %s\n", n_1, s_1);
	printf("n: %i, s: %s\n", n_2, s_2);
	printf("n: %i, s: %s\n", n_3, s_3);
	printf("n: %i, s: %s\n", n_4, s_4);
	*/
	if (strcmp(s_0, "0") != 0)
		test_result = 0;
	if (strcmp(s_1, "-42") != 0)
		test_result = 0;
	if (strcmp(s_2, "42") != 0)
		test_result = 0;
	if (strcmp(s_3, "-2147483648") != 0)
		test_result = 0;	
	if (strcmp(s_4, "2147483647") != 0)
		test_result = 0;
	free(s_0);
	free(s_1);
	free(s_2);
	free(s_3);
	free(s_4);
	return(test_result);
}