#include "so_long.h"

int main(int argc, char **argv)
{
	char **map;

	if (ft_error(argc, argv) == -1)
		return (-1);
	map = map_reader(argv[1]);
	if (map == NULL)
		return (-1);
	return (0);
}
