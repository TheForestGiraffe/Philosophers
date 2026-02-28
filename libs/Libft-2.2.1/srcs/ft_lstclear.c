/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:40:17 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/06 19:11:43 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lst_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = lst_next;
	}
}
