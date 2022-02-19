/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:28:08 by simonwautel       #+#    #+#             */
/*   Updated: 2022/02/19 01:06:24 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_reader(char *name)
{
	int		fd;
	char	*line;
	size_t	height;
	size_t	len;

	height = -1;
	fd = open (name, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line) - 1;
	while (line)
	{
		line = get_next_line(fd);
		if (len != ft_strlen(line) - 1)
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
	return (map_translate(len, height, name));
}

char	**map_translate(int const len, int const height, char *name)
{
	int		fd;
	char	**map;
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	map = malloc(height * sizeof(char *));
	while (i < height)
	{
		map[i] = malloc (len * sizeof(char));
		i++;
	}
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
	return (map);
}
