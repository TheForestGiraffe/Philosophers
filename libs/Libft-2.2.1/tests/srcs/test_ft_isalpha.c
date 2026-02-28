/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:24:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/13 23:38:12 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int test_ft_isalpha(void)
{
    int c = 0;

    while (c <= UCHAR_MAX)
    {
        if ((isalpha(c) > 0 && ft_isalpha(c) > 0) || 
			(isalpha(c) == 0 && ft_isalpha(c) == 0))
        {
			//printf("%c, %i, %i\n", c, ft_isalpha(c), isalpha(c));
			c++;
		}
		else
		{ 
			//printf("%c, %i, %i\n", c, ft_isalpha(c), isalpha(c));
			return (0);
		}
    }
    if (isalpha(EOF) == ft_isalpha(EOF))
		return (1);
	return (0);
}
