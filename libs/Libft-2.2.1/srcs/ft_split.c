/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:41:03 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/12 02:00:51 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static char		**alloc_strings(char const *s, char c, char **str_ptrs_array);
static size_t	check_start(const char *s, char c, size_t i, size_t start);
static void		free_all_previous(char **str_ptrs_array, size_t j);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	nbr_words;
	size_t	size;
	char	**str_ptrs_array;

	i = 0;
	nbr_words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbr_words++;
		i++;
	}
	size = nbr_words + 1;
	str_ptrs_array = (char **)malloc((size) * sizeof(char *));
	if (str_ptrs_array == NULL)
		return (NULL);
	str_ptrs_array[size - 1] = NULL;
	str_ptrs_array = alloc_strings(s, c, str_ptrs_array);
	return (str_ptrs_array);
}

char	**alloc_strings(char const *s, char c, char **str_ptrs_array)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = check_start(s, c, i, start);
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				str_ptrs_array[j] = (char *)malloc(i - start + 2);
				if (str_ptrs_array[j] == NULL)
				{
					free_all_previous(str_ptrs_array, j);
					return (NULL);
				}
				ft_strlcpy(str_ptrs_array[j++], &s[start], i - start + 2);
			}
		}
		i++;
	}
	return (str_ptrs_array);
}

size_t	check_start(const char *s, char c, size_t i, size_t start)
{
	if (i == 0)
		start = i;
	if (i > 0)
	{
		if (s[i - 1] == c)
			start = i;
	}
	return (start);
}

void	free_all_previous(char **str_ptrs_array, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(str_ptrs_array[i]);
	free(str_ptrs_array);
}
