/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:11:47 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/13 23:38:47 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	test_ft_memset(void)
{
	int		c;
	void	*s_memset;
	void	*s_ft_memset;
	size_t	i;
	size_t	size;

	c = 'A';
	size = 1000 * sizeof(char);
	s_ft_memset = malloc(size);
	s_memset = malloc(size);
	if (!(s_ft_memset && s_memset))
	{
		printf("Test_ft_memset: memory allocation for testing failed.\n");
		return (0);
	}
	s_ft_memset = ft_memset(s_ft_memset, c, size);
	s_memset = memset(s_memset, c, size);
	i = 0;
	while (i < size / sizeof(char))
	{
		if(((char *)s_ft_memset)[i] == ((char *)s_memset)[i])
			i++;
		else
			return (0);
	}
	free(s_ft_memset);
	free(s_memset);
	return (1);
}
