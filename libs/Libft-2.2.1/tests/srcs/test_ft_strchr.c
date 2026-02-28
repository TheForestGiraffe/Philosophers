/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:50:45 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/18 13:12:01 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	test_ft_strchr(void)
{
	char	str[] = "Lorem Ipsum.";

	if (ft_strchr(str, 'I') != &str[6])
		return (0);
	if (ft_strchr(str, '\0') != &str[12])
		return (0);
	if (ft_strchr(str, 'a') != NULL)
		return (0);
	return (1);
}