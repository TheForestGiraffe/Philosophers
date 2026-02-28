/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:01:15 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/19 11:52:41 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int test_ft_toupper(void)
{
   int	c;

	c = 0;
	while (c <= 255)
	{
		if (ft_toupper(c) != toupper(c))
			return (0);
		c++;
	}
	if (ft_toupper(EOF) != toupper(EOF))
		return (0);
    return (1);
}
