/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:12:43 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/13 23:38:25 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int test_ft_isascii(void)
{
    int c = 0;

    while (c <= UCHAR_MAX)
    {
        if ((ft_isascii(c) > 0 && isascii(c) > 0) || 
			(ft_isascii(c) == 0 && isascii(c) == 0))
        {
			//printf("%i, %c, %i, %i\n", c, c, ft_isascii(c), isascii(c));
			c++;
		}
		else
		{ 
			//printf("%i, %c, %i, %i\n", c, c, ft_isascii(c), isascii(c));
			return (0);
		}
    }
    if (ft_isascii(EOF) == isascii(EOF))
		return(1);
	return (0);
}
