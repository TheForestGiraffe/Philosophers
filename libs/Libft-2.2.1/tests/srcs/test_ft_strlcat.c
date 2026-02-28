/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:47:54 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/07 00:40:37 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "libft.h"
#include "test_libft.h"


int test_ft_strlcat(void)
{
	char dest1[5] = "ABC";
	char dest2[4] = "ABC";
	char dest3[4] = "ABC";
	char src[] = "DEFG";
	size_t			size0;
	size_t			size1;
	size_t			size2;
	size_t			size3;
	size_t			res;

	size0 = 0;
	size1 = 5;
	size2 = 4;
	size3 = 1;
	//printf("Test: dst: ABC, src: DEFG, size: 0\n");
	res = ft_strlcat(dest1, src, size0);
	//printf("Return (0 + src_len): %zu\n", res);
	//printf("dest: %s\n", dest1);
	if (res != 4 || strcmp(dest1, "ABC"))
		return (0);
	//printf("Test: dst: ABC, src: DEFG, size: 5\n");
	res = ft_strlcat(dest1, src, size1);
	//printf("Return (dest_len + src_len): %zu\n", res);
	//printf("dest: %s\n", dest1);
	if (res != 7 || strcmp(dest1, "ABCD"))
		return (0);
	//printf("Test: dst: ABC, src: DEFG, size: 4\n");
	res = ft_strlcat(dest2, src, size2);
	//printf("Return (dest_len + src_len): %zu\n", res);
    //printf("dest: %s\n", dest2);
	if (res != 7 || strcmp(dest2, "ABC"))
		return (0);
	//printf("Test: dst: ABC, src: DEFG, size: 1\n");
	res = ft_strlcat(dest3, src, size3);
	//printf("Return (dest_len + src_len): %zu\n", res);
    //printf("dest: %s\n", dest3);
	if (res != 5 || strcmp(dest3, "ABC"))
		return (0);
	return (1);
}
