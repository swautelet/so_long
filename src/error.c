#include "so_long.h"

int	ft_error(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("error\nTheres's no map");
		return (-1);
	}
	if (argc > 2)
	{
		printf("error\nthere's too much map");
		return (-1);
	}
	if (ft_strnstr(argv[1], ".ber", SIZE_T_MAX))
	{
		printf("error\nthe map is in the wrong format");
		return (-1);
	}
	return (0);
}
