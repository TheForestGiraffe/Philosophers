/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:12:01 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/06 19:14:42 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl_node	*lst_head = NULL;
	t_gnl_node			*node;
	char				*line;

	line = NULL;
	if ((BUFFER_SIZE < 1) || (fd < 0))
		return (NULL);
	node = search_or_add_node_front(&lst_head, fd);
	if (!node)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
	{
		delete_node(&lst_head, node);
		return (NULL);
	}
	next_line(&node->file, &line);
	if (!line || node->file.bytes_read == -1)
	{
		delete_node(&lst_head, node);
		free(line);
		return (NULL);
	}
	if (node->file.bytes_read == 0 && node->file.position == 0)
		delete_node(&lst_head, node);
	return (line);
}

void	next_line(t_gnl_file *file, char **line)
{
	char	*c;
	size_t	position;
	size_t	length;

	position = 0;
	length = 0;
	c = next_char(file);
	while (c)
	{
		if (position >= length)
		{
			realloc_line(line, &length);
			if (!*line)
				return ;
		}
		(*line)[position++] = *c;
		if (*c == '\n')
		{
			(*line)[position++] = '\0';
			return ;
		}
		c = next_char(file);
	}
	last_line(&position, line);
}

void	last_line(size_t *position, char **line)
{
	if ((*position > 0) && (*line != NULL))
		(*line)[*position] = '\0';
	else
	{
		free(*line);
		*line = NULL;
	}
}

void	realloc_line(char **line, size_t *length)
{
	char	*new_line;
	size_t	size;

	if (*length == 0)
	{
		size = BUFFER_SIZE + 1;
	}
	else
	{
		size = (*length * 2 + 1);
	}
	new_line = (char *)malloc(size);
	if (!new_line)
	{
		free(*line);
		*line = NULL;
		return ;
	}
	if (*line)
	{
		ft_memcpy(new_line, *line, *length);
		free(*line);
	}
	*line = new_line;
	*length = size -1;
}

char	*next_char(t_gnl_file *file)
{
	char	*c;

	if (!file->buffer)
		file->buffer = (char *)malloc(BUFFER_SIZE);
	if (!file->buffer)
		return (NULL);
	if (file->position >= file->bytes_read)
	{
		file->position = 0;
		file->bytes_read = read(file->fd, file->buffer, BUFFER_SIZE);
		if (file->bytes_read == -1 || file->bytes_read == 0)
		{
			free(file->buffer);
			file->buffer = NULL;
			return (NULL);
		}
	}
	c = &file->buffer[file->position];
	file->position++;
	return (c);
}
