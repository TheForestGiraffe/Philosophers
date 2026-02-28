/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:26:19 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/06 19:39:35 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	this_striteri_toupper(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c -32 + i;
}

int	test_ft_striteri(void)
{
	int		test_result;
	char	str_1[] = "Berlin 2025";
	char	str_2[] = "";

	test_result = 1;
	//printf("f: toupper + i. Before: %s\n", str_1);
	ft_striteri(str_1, &this_striteri_toupper);
	//printf("f: toupper + i. After:  %s\n", str_1);
	//printf("f: toupper + i. Before: %s\n", str_2);
	ft_striteri(str_2, &this_striteri_toupper);
	//printf("f: toupper + i. After:  %s\n", str_2);
	if (strcmp(str_1, "BFTOMS 2025") != 0)
		test_result = 0;
	if (strcmp(str_2, "") != 0)
		test_result = 0;
	return (test_result);
}
