/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:35:41 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 13:35:23 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	test_ft_swap(void)
{
	int	a;
	int	b;
	
	a = 348;
	b = 209943;
	ft_swap(&a, &b);
	if (a != 209943)
		return (0);
	if (b != 348)
		return (0);
	return (1);
}
