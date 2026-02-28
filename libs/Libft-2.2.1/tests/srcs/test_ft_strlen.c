/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:11:47 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/15 20:40:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int test_ft_strlen(void)
{
	char	str_1[] = "Hello!";
	char	str_2[] = "";
	char	str_3[] = "Hell'\0'!";

    if (strlen(str_1) == ft_strlen(str_1) &&
		strlen(str_2) == ft_strlen(str_2) &&
		strlen(str_3) == ft_strlen(str_3))
		return (1);
	else
		return (0);
}
