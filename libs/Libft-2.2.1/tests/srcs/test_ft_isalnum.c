/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:11:47 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/13 23:38:04 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int test_ft_isalnum(void)
{
    int c = 0;

    while (c <= UCHAR_MAX)
    {
        if ((isalnum(c) > 0 && ft_isalnum(c) > 0) || 
			(isalnum(c) == 0 && ft_isalnum(c) == 0))
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
    if (ft_isalnum(EOF) == isalnum(EOF))
		return (1);
	return (0);
}
