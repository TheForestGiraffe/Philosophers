/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:51:14 by pedro             #+#    #+#             */
/*   Updated: 2025/05/22 15:44:12 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	test_ft_strlcpy(void)
{
    const char  const_buffer[20] = "23456789012345678902";
    char	    buffer[20] = "23456789012345678902";
    const char  str[] = "Lorem Ipsum";
    int         i;

    // Test if buffer is unchanged with size = 0:
    ft_strlcpy(buffer, str, 0);
    i = 0;
    while (i < 20)
    {
        if (const_buffer[i] != buffer[i])
            return (0);
        i++;
    }
    //printf("Buffer with size = 0 [OK!]: %s\n", buffer);
    // For size = 1, test if \0 is copied into buffer [0]:
    ft_strlcpy(buffer, str, 1);
        if (buffer[0] != '\0')
            return (0);
    //printf("Buffer with size = 1 [OK!]: %s\n", buffer);
    // Test if Lore is copied into buffer [0], and null terminated:
    ft_strlcpy(buffer, str, 5);
    i = 0;
    while (i < 4)
    {
        if (str[i] != buffer[i])
            return (0);
        i++;
    }
    if (buffer[i] != '\0')
        return (0);
    //printf("Buffer with size = 5 [OK!]: %s\n", buffer);
    // Test if full str is copied into buffer, and the rest of the buffer is unchanged [20]
    ft_strlcpy(buffer, str, 20);
    i = 0;
    while (i < 11)
    {
		//printf("Loop 1: %c, %c\n", str[i], buffer[i]);
         if (str[i] != buffer[i])
            return (0);
        i++;
    }
	//printf("%c, %c\n", str[i], buffer[i]);
	if (str[i] != '\0')
		return (0);
	i++;
    while (i < 20)
        {
			//printf("%c, %c\n", buffer[i], const_buffer[i]);
         	if (buffer[i] != const_buffer[i])
            	return (0);
        	i++;
    	}
	//printf("str: %s\n", str);
	//printf("str_cpy: %s\n", buffer);
    //printf("Buffer with size = 20 [OK]: %s\n", buffer);
	
	return (1);
}
