#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <strings.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "get_next_line.h"

int 	ft_error(int argc, char **argv);
char	**map_reader(char *name);
char	**map_translate(const int len, const int height, char *name);

#endif
