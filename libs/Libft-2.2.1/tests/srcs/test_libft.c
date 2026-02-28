/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:16:36 by pecavalc          #+#    #+#             */
/*   Updated: 2025/11/03 15:31:42 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test_libft.h"

int	main()
{
	printf("\n-- Testing Libft --\n");
	printf("\nObs: Test for linked list functions are not included.\n\n");

    print_result(test_ft_isalpha(), "test_ft_isalpha");
	print_result(test_ft_isdigit(), "test_ft_isdigit");
	print_result(test_ft_isalnum(), "test_ft_isalnum");
	print_result(test_ft_isascii(), "test_ft_isascii");
	print_result(test_ft_isprint(), "test_ft_isprint");
	print_result(test_ft_strlen(), "test_ft_strlen");
	print_result(test_ft_memset(), "test_ft_memset");
	print_result(test_ft_bzero(), "test_ft_bzero");
	print_result(test_ft_memcpy(), "test_ft_memcpy");
	print_result(test_ft_memmove_backwardcpy(), "test_ft_memmove_backwardcpy");
	print_result(test_ft_memmove_forwardcpy(), "test_ft_memmove_forwardcpy");
	print_result(test_ft_calloc(), "test_ft_calloc");
	print_result(test_ft_calloc_overflow(), "test_ft_calloc_overflow");
	print_result(test_ft_strlcpy(), "test_ft_strlcpy");
	print_result(test_ft_strlcat(), "test_ft_strlcat");
	print_result(test_ft_toupper(), "test_ft_toupper");
	print_result(test_ft_tolower(), "test_ft_tolower");
	print_result(test_ft_strchr(), "test_ft_strchr");
	print_result(test_ft_strrchr(), "test_ft_strrchr");
	print_result(test_ft_strncmp(), "test_ft_strncmp");
	print_result(test_ft_memchr(), "test_ft_memchr");
	print_result(test_ft_memcmp(), "test_ft_memcmp");
	print_result(test_ft_strnstr(), "test_ft_strnstr");
	print_result(test_ft_atoi(), "test_ft_atoi");
	print_result(test_ft_strtol(), "test_ft_strtol");
	print_result(test_ft_strdup(), "test_ft_strdup");
	print_result(test_ft_substr(), "test_ft_substr");
	print_result(test_ft_strjoin(), "test_ft_strjoin");
	print_result(test_ft_strtrim(), "test_ft_strtrim");
	print_result(test_ft_split(), "test_ft_split");
	print_result(test_ft_swap(), "test_ft_swap");
	print_result(test_ft_itoa(), "test_ft_itoa");
	print_result(test_ft_strmapi(), "test_ft_strmapi");
	print_result(test_ft_striteri(), "test_ft_striteri");
	print_result(test_ft_putchar_fd(), "test_ft_putchar_fd");
	print_result(test_ft_putstr_fd(), "test_ft_putstr_fd");
	print_result(test_ft_putendl_fd(), "test_ft_putendl_fd");
	print_result(test_ft_putnbr_fd(), "test_ft_putnbr_fd");
	print_result(test_get_next_line(), "get_next_line");
	test_ft_printf();	

	printf("\n\n-- End of test. --\n\n");
    return (0);
}

void	print_result(int ft_return, char *ft_name)
{
	if (ft_return == 1)
		printf("%-30s [Passed]\n", ft_name);
	else if (ft_return == 0)
		printf("%-30s [Failed]\n", ft_name);
	else if (ft_return == -1)
		{}
	else
		printf("%s:	The test function must return either 0 or 1. The test failed.\n", ft_name);
}
