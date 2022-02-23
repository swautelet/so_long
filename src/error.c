/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:08 by swautele          #+#    #+#             */
/*   Updated: 2022/02/23 13:24:05 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int argc, char **argv)
{
	char	*ext;

	ext = ".ber";
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
	if (ft_strncmp(ft_strnstr(argv[1], ".ber", SIZE_T_MAX), ext, 4) != 0)
	{
		printf("error\nthe map is in the wrong format");
		return (-1);
	}
	return (0);
}

int	map_error(t_list *map)
{
	size_t	len;
	size_t	height;
	int		i;

	i = 0;
	len = ft_strlen(map->content);
	while (map->content[i] != '\n')
	{
		if (map->content[i] != '1')
		{
			printf("error\nthere miss a wall around the map");
			return (-1);
		}
		i++;
	}
	height = 1;
	while (map->next != NULL)
	{
		map = map->next;
		if (ft_strlen(map->content) != len)
		{
			printf("error\nthe map is not a rectangle");
			return (-1);
		}
		if (map->content[0] != '1' || map->content[len])
		{
			printf("error\nthere miss a wall around the map");
			return (-1);
		}
		height++;
	}
	while (map->content[i] != '\n')
	{
		if (map->content[i] != '1')
		{
			printf("error\nthere miss a wall around the map");
			return (-1);
		}
		i++;
	}
	if (len < 3 || height < 3)
	{
		printf("error\nthe map is too short");
		return (-1);
	}
	return (0);
}
