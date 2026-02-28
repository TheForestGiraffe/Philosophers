/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:37:04 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/07 00:58:29 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int	test_ft_putchar_fd(void)
{
	int		fd;
	int		i;
	char	*text = "Written from ft_putchar_fd.c.";

	fd = open("_test_ft_putchar_fd_test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Cannot read file.\n");
		return (0);
	}
	i = 0;
	while (text[i])
	{
    	ft_putchar_fd(text[i++], fd);
	}
	close(fd);
	printf("%-30s [File created, inspect visually: _test_ft_putchar_fd_test.txt]\n", "test_ft_putchar_fd");
	return (-1);
}
