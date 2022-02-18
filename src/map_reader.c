#include "so_long.h"

char	**map_reader(char *name)
{
	int		fd;
	char	*line;
	size_t	height;
	size_t	len;
	char	**map;

	high = 1;
	fd = open (name, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
	line = get_next_line(fd);
	if (len != ft_strlen(line))
		{
			printf("error\nthe map is not a rectangle");
			return (NULL);
		}
	height++;
	}
	close (fd);
	if (height < 3 || len < 3)
	{
		printf("error\nthe map is too little");
		return (NULL);
	}
	map = map_translate(len, height, name);
	return (map);
}

char	**map_translate(const int len, const int height, char *name)
{
	int		fd;
	char 	map[len][height];
	int		i;
	int		j;
	char 	*line;

	i = 0;
	j = 0;
	fd = open(name, O_RDONLY);
	while (j < height)
	{
		line = get_next_line(fd);
		while (i < len)
		{
			map[i][j] = line[i];
			i++;
		}
		j++;
		i = 0;
	}
	close(fd);
}
