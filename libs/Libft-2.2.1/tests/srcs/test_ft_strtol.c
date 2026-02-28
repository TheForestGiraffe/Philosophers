/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:50:00 by pecavalc          #+#    #+#             */
/*   Updated: 2025/11/03 15:45:47 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "libft.h"

int	test_ft_strtol(void)
{
	long	num;
	int		ret;

	char line_0[] = " +13984234";
	char line_1[] = " -126565";
	char line_2[] = " -2";
	char line_3[] = "   ";
	char line_4[] = " ---+";
	char line_5[] = "9223372036854775807"; // LONG_MAX
	char line_6[] = "-9223372036854775808"; // LONG_MIN
	char line_7[] = " +13984234ab567";
	char line_8[] = " -126565!ab567";

	ret = ft_strtol(line_0, &num);
	if (ret != 1 || num != 13984234)
		return (0);

	ret = ft_strtol(line_1, &num);
	if (ret != 1 || num != -126565)
		return (0);

	ret = ft_strtol(line_2, &num);
	if (ret != 1 || num != -2)
		return (0);

	ret = ft_strtol(line_3, &num);
	if (ret != -1)
		return (0);

	ret = ft_strtol(line_4, &num);
	if (ret != -1)
		return (0);

	ret = ft_strtol(line_5, &num);
	if (ret != 1 || num != LONG_MAX)
		return (0);

	ret = ft_strtol(line_6, &num);
	if (ret != 1 || num != LONG_MIN)
		return (0);

	ret = ft_strtol(line_7, &num);
	if (ret != -1)
		return (0);

	ret = ft_strtol(line_8, &num);
	if (ret != -1)
		return (0);

	return (1);
}