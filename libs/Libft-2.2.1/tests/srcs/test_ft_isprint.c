/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:11:47 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/13 23:38:39 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int test_ft_isprint(void)
{
    int c = 0;

    while (c <= UCHAR_MAX)
    {
        if ((isprint(c) > 0 && ft_isprint(c) > 0) || 
			(isprint(c) == 0 && ft_isprint(c) == 0))
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
    if (ft_isprint(EOF) == isprint(EOF))
		return (1);
	return (0);
}
