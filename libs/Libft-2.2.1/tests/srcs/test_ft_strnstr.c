/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:03:55 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/22 16:17:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

int	test_ft_strnstr(void)
{
	
	/*printf("1:%s\n", ft_strnstr("Hello World!", "llOllo", 13));
	printf("2:%s\n", ft_strnstr("Hello World!", "World", 13));
	printf("3:%s\n", ft_strnstr("Hello World!", "World", 5));
	printf("4:%s\n", ft_strnstr("Hello World!", "", 13));
	printf("5:%s\n", ft_strnstr("Hello World! ello", "ello", 18));
	printf("6:%s\n", ft_strnstr("Helllo World! ello", "ello", 18));
	printf("7:%s\n", ft_strnstr("Hello World, hello!", "World", 8));
	*/
	if (ft_strnstr("Hello World!", "llOllo", 13) != NULL)
		return (0);
	if (strncmp(ft_strnstr("Hello World!", "World", 13), "World!", 13))
		return (0);
	if (ft_strnstr("Hello World!", "World", 5) != NULL)
		return (0);
	if (strncmp(ft_strnstr("Hello World!", "", 13), "Hello World!", 13))
		return (0);
	if (strncmp(ft_strnstr("Hello World! ello", "ello", 18), "ello World! ello", 18))
		return (0);
	if (strncmp(ft_strnstr("Helllo World! ello", "ello", 18), "ello", 18))
		return (0);
	if (ft_strnstr("Hello World, hello!", "World", 8) != NULL)
		return (0);
	return (1);
}
