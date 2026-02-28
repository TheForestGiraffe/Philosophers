/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:22:45 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/18 19:45:16 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

int	test_ft_strncmp(void)
{
	//printf("ft_strncmp Hello, Hello, 5: %i\n", ft_strncmp("Hello", "Hello", 5));
	//printf("   strncmp Hello, Hello, 5: %i\n", strncmp("Hello", "Hello", 5));
	if (ft_strncmp("Hello", "Hello", 5) != strncmp("Hello", "Hello", 5))
		return (0);
	//printf("ft_strncmp HeLlo, Hello, 2: %i\n", ft_strncmp("HeLlo", "Hello", 2));
	//printf("   strncmp HeLlo, Hello, 2: %i\n", ft_strncmp("HeLlo", "Hello", 2));
	if (ft_strncmp("HeLlo", "Hello", 2) != strncmp("HeLlo", "Hello", 2))
		return (0);
	//printf("ft_strncmp HeLlo, Hello, 4: %i\n", ft_strncmp("HeLlo", "Hello", 4));
	//printf("   strncmp HeLlo, Hello, 4: %i\n", strncmp("HeLlo", "Hello", 4));
	if (ft_strncmp("HeLlo", "Hello", 4) >= 0 && strncmp("HeLlo", "Hello", 4) >= 0)
		return (0);
	//printf("ft_strncmp Hell, Hello, 4: %i\n", ft_strncmp("Hell", "Hello", 4));
	//printf("   strncmp Hell, Hello, 4: %i\n", strncmp("Hell", "Hello", 4));
	if (ft_strncmp("Hell", "Hello", 4) != strncmp("Hell", "Hello", 4))
		return (0);
	//printf("ft_strncmp Hello, Hell, 4: %i\n", ft_strncmp("Hello", "Hell", 4));
	//printf("   strncmp Hello, Hell, 4: %i\n", strncmp("Hello", "Hell", 4));
	if (ft_strncmp("Hello", "Hell", 4) != strncmp("Hello", "Hell", 4))
		return (0);
	//printf("ft_strncmp Hello, Hell, 5: %i\n", ft_strncmp("Hello", "Hell", 5));
	//printf("   strncmp Hello, Hell, 5: %i\n", strncmp("Hello", "Hell", 5));
	if (ft_strncmp("Hello", "Hell", 5) <= 0 && strncmp("Hello", "Hell", 5) <= 0)
		return (0);
	//printf("ft_strncmp Empty, Empty: %i\n", ft_strncmp("","", 1));
	//printf("   strncmp Empty, Empty: %i\n", strncmp("","", 1));
	if (ft_strncmp("", "", 1) != strncmp("", "", 1))
		return (0);
	return (1);
}
