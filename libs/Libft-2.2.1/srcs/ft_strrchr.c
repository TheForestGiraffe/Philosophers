/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:41:30 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/18 13:08:45 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr_to_c;

	ptr_to_c = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			ptr_to_c = (&((char *)s)[i]);
		i++;
	}
	if (c == '\0')
		ptr_to_c = (&((char *)s)[i]);
	return (ptr_to_c);
}
