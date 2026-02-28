/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:50:45 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/22 16:34:57 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	test_ft_memchr(void)
{
	char			c_str[] = {'L','o','r','e','m',' ','\0',' ','I','p','s','u','m','.'};
	void			*str;
	unsigned char	*ptr;

	str = (void *)c_str;
	ptr = (unsigned char *)str;

	if (ft_memchr(str, 's', 14) != (void *)(ptr + 10))
		return (0);
	if (ft_memchr(str, 'I', 5) != NULL)
		return (0);
	if (ft_memchr(str, '\0', 14) != (void *)(ptr + 6))
		return (0);
	if (ft_memchr(str, 'a', 14) != NULL)
		return (0);
	return (1);
}
