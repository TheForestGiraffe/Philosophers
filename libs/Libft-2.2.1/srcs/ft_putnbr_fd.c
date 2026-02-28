/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:54:19 by pecavalc          #+#    #+#             */
/*   Updated: 2025/05/20 18:00:28 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	digit;
	char	digit_char;

	digit = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		digit *= -1;
	}
	if (digit >= 10)
		ft_putnbr_fd(digit / 10, fd);
	digit_char = digit % 10 + '0';
	write(fd, &digit_char, 1);
}
