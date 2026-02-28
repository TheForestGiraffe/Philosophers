/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:27:41 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/18 19:48:32 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

int	test_ft_memcmp(void)
{
	char	c_str_1[] = {'H','e','\0','l','l','o'};
	char	c_str_2[] = {'H','e','\0','l','l','\0'};
	void	*str_1;
	void	*str_2;

	str_1 = (void *)c_str_1;
	str_2 = (void *)c_str_2;

	//printf("ft_memcmp He'0'llo, He'0'll, 6: %i\n", ft_memcmp(str_1, str_2, 6));
	//printf("   memcmp He'0'llo, He'0'll, 6: %i\n", memcmp(str_1, str_2, 6));
	if (ft_memcmp(str_1, str_2, 6) <= 0 && memcmp(str_1, str_2, 6) <= 0)
		return (0);
	//printf("ft_memcmp Hello, Hello, 5: %i\n", ft_memcmp("Hello", "Hello", 5));
	//printf("   memcmp Hello, Hello, 5: %i\n", memcmp("Hello", "Hello", 5));
	if (ft_memcmp("Hello", "Hello", 5) != memcmp("Hello", "Hello", 5))
		return (0);
	//printf("ft_memcmp HeLlo, Hello, 2: %i\n", ft_memcmp("HeLlo", "Hello", 2));
	//printf("   memcmp HeLlo, Hello, 2: %i\n", ft_memcmp("HeLlo", "Hello", 2));
	if (ft_memcmp("HeLlo", "Hello", 2) != memcmp("HeLlo", "Hello", 2))
		return (0);
	//printf("ft_memcmp HeLlo, Hello, 4: %i\n", ft_memcmp("HeLlo", "Hello", 4));
	//printf("   memcmp HeLlo, Hello, 4: %i\n", memcmp("HeLlo", "Hello", 4));
	if (ft_memcmp("HeLlo", "Hello", 4) >= 0 && memcmp("HeLlo", "Hello", 4) >= 0)
		return (0);
	//printf("ft_memcmp Hell, Hello, 4: %i\n", ft_memcmp("Hell", "Hello", 4));
	//printf("   memcmp Hell, Hello, 4: %i\n", memcmp("Hell", "Hello", 4));
	if (ft_memcmp("Hell", "Hello", 4) != memcmp("Hell", "Hello", 4))
		return (0);
	//printf("ft_memcmp Hello, Hell, 4: %i\n", ft_memcmp("Hello", "Hell", 4));
	//printf("   memcmp Hello, Hell, 4: %i\n", memcmp("Hello", "Hell", 4));
	if (ft_memcmp("Hello", "Hell", 4) != memcmp("Hello", "Hell", 4))
		return (0);
	//printf("ft_memcmp Hello, Hell, 5: %i\n", ft_memcmp("Hello", "Hell", 5));
	//printf("   memcmp Hello, Hell, 5: %i\n", memcmp("Hello", "Hell", 5));
	if (ft_memcmp("Hello", "Hell", 5) <= 0 && memcmp("Hello", "Hell", 5) <= 0)
		return (0);
	//printf("ft_memcmp Empty, Empty: %i\n", ft_memcmp("","", 1));
	//printf("   memcmp Empty, Empty: %i\n", memcmp("","", 1));
	if (ft_memcmp("", "", 1) != memcmp("", "", 1))
		return (0);
	return (1);
}
