#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

int	test_get_next_line(void)
{
	int		fd;
	
	fd = open("srcs/test_get_next_line_lorem.txt", O_RDONLY);

	if (fd < 0)
	{
		printf("Could not open the file.\n");
		return (0);
	}

	if (strncmp(get_next_line(fd), "Lorem ipsum dolor sit amet.", 27))
		return (0);
	if (strncmp(get_next_line(fd), "\n", 1))
		return (0);
	if (strncmp(get_next_line(fd), "Nulla magna metus, ornare et mi nec, consectetur ullamcorper neque.", 67))
		return (0);

	close(fd);
	return (1);
}
