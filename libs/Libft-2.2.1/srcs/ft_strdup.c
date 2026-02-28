/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:04:26 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/18 22:38:24 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s1_dup;

	size = (ft_strlen(s1) + 1) * sizeof(char);
	s1_dup = (char *)malloc(size);
	if (s1_dup == NULL)
		return (NULL);
	ft_strlcpy(s1_dup, s1, size);
	return (s1_dup);
}
