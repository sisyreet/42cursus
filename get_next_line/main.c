#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line = 0;

	fd = open("text2.txt", O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		if (line == 0)
			return (0);
		printf("%s", line);
	}
	close(fd);
	return (0);
}
