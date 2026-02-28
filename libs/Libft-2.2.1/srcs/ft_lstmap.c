/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:11:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/06 19:12:29 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;

	if (!lst || !f || !del)
		return (NULL);
	lst_new = ft_lstnew(f(lst->content));
	if (!lst_new)
		return (NULL);
	if (lst->next != NULL)
	{
		lst_new->next = ft_lstmap(lst->next, f, del);
		if (!lst_new->next)
		{
			ft_lstdelone(lst_new, del);
			return (NULL);
		}
	}
	else
		lst_new->next = NULL;
	return (lst_new);
}
