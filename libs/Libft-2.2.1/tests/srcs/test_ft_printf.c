/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:42:17 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/07 00:23:21 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "test_libft.h"
#include "libft.h"

void	test_ft_printf(void)
{
	printf("\n\n-- For ft_printf inspect the results and compare them visually below: -- \n\n");
	test_c();
	test_s();
	test_d();
	test_i();
	test_u();
	test_x();
	test_X();
	test_p();
	//test_empty_str();
	//test_null_str();
	test_double_percent();
	test_all_again();
}

void	test_c(void)
{
	char	arg_1;
	char	arg_2;
	int		ret_or;
	int		ret_ft;

	printf("Test %%c:\n");
	arg_1 = 'A';
	arg_2 = '~';
	ret_or = printf("or_printf: %c, %c\n", arg_1, arg_2);
	ret_ft = ft_printf("ft_printf: %c, %c\n", arg_1, arg_2);
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}

void	test_s(void)
{
	char	*arg_1;
	char	*arg_2;
	int		ret_or;
	int		ret_ft;

	printf("Test %%s:\n");
	arg_1 = "Short string.";
	arg_2 = "Longer string: Lorem ipsum dolor amet, consectetur adipiscing.";
	ret_or = printf("or_printf: %s, %s\n", arg_1, arg_2);
	ret_ft = ft_printf("ft_printf: %s, %s\n", arg_1, arg_2);
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}

void	test_d(void)
{
	int		arg_1;
	int		arg_2;
	int		ret_or;
	int		ret_ft;

	printf("Test %%d:\n");
	arg_1 = 42;
	arg_2 = -8572349;
	ret_or = printf("or_printf: %d, %d\n", arg_1, arg_2);
	ret_ft = ft_printf("ft_printf: %d, %d\n", arg_1, arg_2);
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}

void	test_i(void)
{
	int		arg_1;
	int		arg_2;
	int		ret_or;
	int		ret_ft;

	printf("Test %%i:\n");
	arg_1 = 42;
	arg_2 = INT_MIN;
	ret_or = printf("or_printf: %i, %i\n", arg_1, arg_2);
	ret_ft = ft_printf("ft_printf: %i, %i\n", arg_1, arg_2);
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}

void	test_u(void)
{
	int		arg_1;
	int		arg_2;
	int		ret_or;
	int		ret_ft;

	printf("Test %%u:\n");
	arg_1 = 42;
	arg_2 = -8572349;
	ret_or = printf("or_printf: %u, %u\n", arg_1, arg_2);
	ret_ft = ft_printf("ft_printf: %u, %u\n", arg_1, arg_2);
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}

void	test_x(void)
{
	int		arg_1;
	int		arg_2;
	int		ret_or;
	int		ret_ft;

	printf("Test %%x:\n");
	arg_1 = 42873;
	arg_2 = -4293;
	ret_or = printf("or_printf: %x, %x\n", arg_1, arg_2);
	ret_ft = ft_printf("ft_printf: %x, %x\n", arg_1, arg_2);
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}

void	test_X(void)
{
	int		arg_1;
	int		arg_2;
	int		ret_or;
	int		ret_ft;

	arg_1 = 42;
	arg_2 = -42;
	printf("Test %%X:\n");
	ret_or = printf("or_printf: %X, %X\n", arg_1, arg_2);
	ret_ft = ft_printf("ft_printf: %X, %X\n", arg_1, arg_2);
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}

void	test_p(void)
{
	int		arg_1;
	int		arg_2;
	void	*ptr_1;
	void	*ptr_2;
	int		ret_or;
	int		ret_ft;

	printf("Test %%:p\n");
	arg_1 = 443542;
	arg_2 = -42433;
	ptr_1 = &arg_1;
	ptr_2 = &arg_2;
	ret_or = printf("or_printf: %p, %p\n", ptr_1, ptr_2);
	ret_ft = ft_printf("ft_printf: %p, %p\n", ptr_1, ptr_2);
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}
/*
void	test_empty_str(void)
{
	int		ret_or;
	int		ret_ft;

	printf("Test empty string:\n");
	ret_or = printf("");
	printf("\n");
	ret_ft = ft_printf("");
	printf("\n");
	printf("ret_or: %u\n", ret_or);
	printf("ret_ft: %u\n", ret_ft);
	printf("\n");
}

void	test_null_str(void)
{
	int		ret_or;
	int		ret_ft;

	printf("Test null string:\n");
	ret_or = printf(NULL);
	printf("\n");
	ret_ft = ft_printf(NULL);
	printf("\n");
	printf("ret_or: %i\n", ret_or);
	printf("ret_ft: %i\n", ret_ft);
	printf("\n");
}
*/
void	test_double_percent(void)
{
	int		ret_or;
	int		ret_ft;

	printf("Test %%%%:\n");
	ret_or = printf("or_printf: %%, %%\n");
	ret_ft = ft_printf("ft_printf: %%, %%\n");
	printf("ret_or: %i \nret_ft: %i\n\n", ret_or, ret_ft);
}

void	test_all_again(void)
{
	char	*nu = NULL;
	int		count;
	void	*p1 = NULL;
	void	*p2 = NULL;

			printf("\nft:\n");
	count = ft_printf("This is with NULL passed as string: %s\n", nu);
	ft_printf("%i\n", count);

	printf("\nprintf:\n");
	count = printf("This is with NULL passed as string: %s\n", nu);
	printf("%i\n", count);
	
	char	*str1 = "Hello World!";
	int	dnum = 42;
	void	*test;
	test = str1;
	unsigned int unum = 4000000000;
	unsigned int ull = 4187654321;
	
	printf("\nft:\n");
	count = ft_printf("%s", str1);
	printf("\nTotal characters(ft)= %i\n", count);
	printf("printft:\n");
	count = printf("%s", str1);
	printf("\nTotal characters(printf) = %i\n", count);
	
	printf("\nft:\n");
	count = ft_printf("Favorite Letter: %c\n", 'J');
	printf("ft Total characters = %i\n", count);
	printf("printf:\n");
	count = printf("Favorite Letter: %c\n", 'J');
	printf("printf Total characters = %i\n", count);
	
	printf("\nft:\n");
	count = ft_printf("Test %%s: Let's %s\n", "Party");
	printf("ft Total characters = %i\n", count);
	printf("printf:\n");
	count = printf("Test %%s: Let's %s\n", "Party");
	printf("printf Total characters = %i\n", count);

	printf("\nft:\n");
	count = ft_printf("Test %%d: Number = %d\n", dnum);
	printf("ft Total characters = %i\n", count);
	printf("printf:\n");
	count = printf("Test %%d: Number = %d\n", dnum);
	printf("printf Total characters = %i\n", count);
	
	printf("\nft:\n");
	count = ft_printf("Test %%u: Number = %u\n", unum);
	printf("ft Total characters = %i\n", count);
	printf("printf:\n");
	count = printf("Test %%u: Number = %u\n", unum);
	printf("printf Total characters = %i\n", count);

	printf("\nft:\n");
	count = ft_printf("Test %%x: Number = %x\n", ull);
	printf("ft Total characters = %i\n", count);
	printf("printf:\n");
	count = printf("Test %%x: Number = %x\n", ull);
	printf("printf Total characters = %i\n", count);

	printf("\nft:\n");
	count = ft_printf("Test %%X: Number = %X\n", ull);
	printf("ft Total characters = %i\n", count);
	printf("printf:\n");
	count = printf("Test %%X: Number = %X\n", ull);
	printf("printf Total characters = %i\n", count);
	
	printf("\nft:\n");
	count = ft_printf("Test %%p: Numbefjsdfr = %p\n", test);
	printf("ft Total characters = %i\n", count);
	printf("printf:\n");
	count = printf("Test %%p: Nfsadfumber = %p\n", test);
	printf("printf Total characters = %i\n", count);

	printf("\nft:\n");
	count = ft_printf(" %p %p ", p1, p2);
	ft_printf("\n%i\n", count);

	printf("\nprintf:\n");
	count = printf(" %p %p ", p1, p2);
	printf("\n%i\n", count);

		printf("\nft:\n");
	count = ft_printf(" %s %d", "K", 56844);
	ft_printf("\n%i\n", count);

	printf("\nprintf:\n");
	count = printf(" %s %d", "K", 56844);
	printf("\n%i\n", count);
}
