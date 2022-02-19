#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <strings.h>
#include <errno.h>
#include <limits.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int 	ft_error(int argc, char **argv);
char	**map_reader(char *name);
char	**map_translate(int const len, int const height, char *name);
char	*get_next_line(int fd);
char	*ft_straddback(char *result, char *buffer, ssize_t size);
size_t	ft_strlengnl(char *str);
int		ft_end_of_line(char *str);
char	*ft_initialize(char *buffer);
char	*gnl(char *result, char *buffer, int size, int fd);
void	ft_straddback2(char *newresult, char *buffer, ssize_t i, ssize_t size);
void	free_map(char **map);

#endif
