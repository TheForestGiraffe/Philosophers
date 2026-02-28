/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:02:45 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/19 00:15:41 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	test_ft_strjoin(void)
{
	char	s1[] = "Lorem ";
	char	s2[] = "Ipsum.";
	char	*s12;

	s12 = ft_strjoin(s1, s2);
	//printf("s1: %s\n", s1);
	//printf("s2: %s\n", s2);
	//printf("strjoin(s1, s2): %s\n", s12);
	if (strncmp(s12, "Lorem Ipsum.", 13) != 0)
	{
		free(s12);
		return (0);
	}
	free(s12);
	return (1);
}
