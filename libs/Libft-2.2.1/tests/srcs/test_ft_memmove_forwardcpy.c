/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove_forwardcpy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:40:02 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/07 00:39:21 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <string.h>
#include "test_libft.h"

int	test_ft_memmove_forwardcpy(void)
{
	char	buffer[20] = {0};
	char	*dest = buffer;
	char	*src = buffer + 3;
	char	src_target[] = "em Ipsum";
	char	dest_target[] = "Lorem Ipsum";
	size_t	i;

	strcpy(src, "Lorem Ipsum");
	//printf("\nTesting ft_memmove for des = src - 3 (forward copy):\n");
	//printf("src before: %s\n", src);
	ft_memmove(dest, src, 12);
	//printf("src after: %s\n", src);
	//printf("dest: %s\n\n", dest);

	i = 0;
	while (src_target[i])
	{
		if (src[i] == src_target[i])
			i++;
		else
			return (0);
	}
	i = 0;
	while (dest_target[i])
	{
		if (dest[i] == dest_target[i])
			i++;
		else
			return (0);
	}
	return (1);
}
