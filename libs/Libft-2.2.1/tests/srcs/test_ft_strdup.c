/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:14:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/18 22:56:59 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	test_ft_strdup(void)
{
    char	src[] = "The 42 norm requires one variable declaration per line.";
    char	*src_dup;
	char	*src_dup_ft;

    src_dup = strdup(src);
	src_dup_ft = ft_strdup(src);

	//printf("src:       %s\n", src);
    //printf("strdup:    %s\n", src_dup);
    //printf("ft_strdup: %s\n", src_dup_ft);

	if (strcmp(src_dup, src_dup_ft) != 0)
	{
		free(src_dup);
		free(src_dup_ft);
		return (0);
	}
	free(src_dup);
	free(src_dup_ft);
    return (1);
}