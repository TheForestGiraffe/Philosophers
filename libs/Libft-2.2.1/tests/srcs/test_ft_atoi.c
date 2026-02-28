/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:35:41 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/18 20:40:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	test_ft_atoi(void)
{
	char line_0[] = " +13984234ab567";
	char line_1[] = " -126565!ab567";
	char line_2[] = " -2jw";
	char line_3[] = "   ";
	char line_4[] = " ---+";

	/*
	printf("%i\n", ft_atoi(line_0));
	printf("%i\n", ft_atoi(line_1));
	printf("%i\n", ft_atoi(line_2));
	printf("%i\n", ft_atoi(line_3));
	printf("%i\n", ft_atoi(line_4));
	*/
	if (ft_atoi(line_0) != 13984234)
		return (0);
	if (ft_atoi(line_1) != -126565)
		return (0);
	if (ft_atoi(line_2) != -2)
		return (0);
	if (ft_atoi(line_3) != 0)
		return (0);
	if (ft_atoi(line_4) != 0)
		return (0);
	return (1);
}
