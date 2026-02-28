/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:20 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/22 20:57:49 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	test_ft_strtrim(void)
{
	int		test_result;
	char	str_1[] = "4224Berlin2442";
	char	str_2[] = "";
	char	str_4[] = "-4224Berlin2442-";
	char	str_5[] = "422442";
	char	str_6[] = "422442";
	char	str_7[] = "aaaaaaaaa";
	char	*trimmed_str_1;
	char	*trimmed_str_2;
	char	*trimmed_str_3;
	char	*trimmed_str_4;
	char	*trimmed_str_5;
	char	*trimmed_str_6;
	char	*trimmed_str_7;

	test_result = 1;
	trimmed_str_1 = ft_strtrim(str_1, "42");
	trimmed_str_2 = ft_strtrim(str_2, "42");
	trimmed_str_3 = ft_strtrim(NULL, "42");
	trimmed_str_4 = ft_strtrim(str_4, "42");
	trimmed_str_5 = ft_strtrim(str_5, "42");
	trimmed_str_6 = ft_strtrim(str_6, "");
	trimmed_str_7 = ft_strtrim(str_7, "a");
	
	//printf("1. ft_strtrim(4224Berlin2442, 42): $%s$\n", trimmed_str_1);
	if (strcmp(trimmed_str_1, "Berlin") != 0)
		test_result = 0;
	//printf("2. ft_strtrim("", 42): $%s$\n", trimmed_str_2);
	if (strcmp(trimmed_str_2, "") != 0)
		test_result = 0;	
	//printf("3. ft_strtrim(NULL, 42): $%s$\n", trimmed_str_3);
	if (trimmed_str_3 != NULL)
		test_result = 0;	
	//printf("4. ft_strtrim(-4224Berlin2442-, 42): $%s$\n", trimmed_str_4);
	if (strcmp(trimmed_str_4, str_4) != 0)
		test_result = 0;	
	//printf("5. ft_strtrim(422422, 42): $%s$\n", trimmed_str_5);
	if (strcmp(trimmed_str_5, "") != 0)
		test_result = 0;	
	//printf("6. ft_strtrim(422442, ""): $%s$\n", trimmed_str_6);
	if (strcmp(trimmed_str_6, str_6) != 0)
		test_result = 0;	
	//printf("7. ft_strtrim(aaaaaaaaa, a): $%s$\n", trimmed_str_7);
	if (strcmp(trimmed_str_7, "") != 0)
		test_result = 0;	
	free(trimmed_str_1);
	free(trimmed_str_2);
	free(trimmed_str_3);
	free(trimmed_str_4);
	free(trimmed_str_5);
	free(trimmed_str_6);
	free(trimmed_str_7);
	return (test_result);
}