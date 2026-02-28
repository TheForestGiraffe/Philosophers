/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:08:35 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/13 23:38:32 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	test_ft_isdigit(void)
{
	int c = 0;

    while (c <= UCHAR_MAX)
    {
        if ((isdigit(c) > 0 && ft_isdigit(c) > 0) ||
			(isdigit(c) == 0 && ft_isdigit(c) == 0))
        {
			//printf("%c, %i, %i\n", c, ft_isdigit(c), isdigit(c));
			c++;
		}
		else
		{
			//printf("%c, %i, %i\n", c, ft_isdigit(c), isdigit(c));
			return (0);
		}
    }
    if (isdigit(EOF) == ft_isdigit(EOF))
		return (1);
	return (0);
}
