#include "so_long.h"

int	map_reader(char *name)
{
	int		fd;
	char	*line;
	ssize_t	num;

	fd = open (name, O_RDONLY);
	line = "";
	while (line)
	{
	line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
