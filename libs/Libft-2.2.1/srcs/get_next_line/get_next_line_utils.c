/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:12:01 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/06 17:26:24 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

t_gnl_node	*search_or_add_node_front(t_gnl_node **lst_head, int fd)
{
	t_gnl_node			*node;

	node = *lst_head;
	while (node)
	{
		if (node->file.fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_gnl_node *)malloc(sizeof(t_gnl_node));
	if (!node)
		return (NULL);
	node->file.fd = fd;
	node->file.buffer = NULL;
	node->file.position = 0;
	node->file.bytes_read = 0;
	node->previous = NULL;
	node->next = *lst_head;
	if (*lst_head)
		(*lst_head)->previous = node;
	*lst_head = node;
	return (node);
}

void	delete_node(t_gnl_node **lst_head, t_gnl_node *node)
{
	if (!node || !lst_head)
		return ;
	if (*lst_head == node)
		*lst_head = node->next;
	if (node->previous)
		node->previous->next = node->next;
	if (node->next)
		node->next->previous = node->previous;
	if (node->file.buffer)
	{
		free (node->file.buffer);
		node->file.buffer = NULL;
	}
	free(node);
	node = NULL;
}
