/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:11:47 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/15 22:55:44 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	test_ft_memcpy(void)
{
	void	*src = "Lorem ipsum";
	void	*dest_memcpy;
	void	*dest_ft_memcpy;
	size_t	i;
	size_t	size;

	size = 12 * sizeof(char);
	dest_ft_memcpy = malloc(size);
	dest_memcpy = malloc(size);
	if (!(dest_ft_memcpy && dest_memcpy))
	{
		printf("Test_ft_memset: memory allocation for testing failed.\n");
		return (0);
	}
	dest_ft_memcpy = ft_memcpy(dest_ft_memcpy, src, size / sizeof(char));
	dest_memcpy = memcpy(dest_memcpy, src, size / sizeof(char));
	i = 0;
	while (i < size / sizeof(char))
	{
		if(((unsigned char *)dest_ft_memcpy)[i] == ((unsigned char *)dest_memcpy)[i])
		{
			i++;
		}
		else
			return (0);
	}
	// Print to terminal for visual inspection:
	/*printf("dest_ft_memcpy: ");
	i = 0;
	while (i < size / sizeof(char))
		printf("%c", ((unsigned char *)dest_ft_memcpy)[i++]);
	printf("\n");
	printf("dest_memcpy:    ");
	i = 0;
	while (i < size / sizeof(char))
		printf("%c", ((unsigned char *)dest_memcpy)[i++]);
	printf("\n");
	*/
	free(dest_ft_memcpy);
	free(dest_memcpy);
	return (1);
}
