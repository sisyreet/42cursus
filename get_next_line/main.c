//#include "get_next_line.h"
//#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

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
		free(line);
	}
	close(fd);
	//printf("%ld - number of file descropitors\n", sysconf(_SC_OPEN_MAX));
	return (0);
}
