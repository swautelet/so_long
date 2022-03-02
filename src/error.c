/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:08 by swautele          #+#    #+#             */
/*   Updated: 2022/03/02 18:31:35 by swautele         ###   ########.fr       */
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

int	map_error(t_list_c *map)
{
	size_t	len;
	size_t	height;
	int		i;
	int		player;
	int		exit;
	int		collectible;

	i = 0;
	exit = 0;
	player = 0;
	collectible = 0;
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
		i = 0;
		while(map->content[i] != '\n')
		{
			if (map->content[i] == 'P')
				player++;
			i++;
		}
		i = 0;
		while(map->content[i] != '\n')
		{
			if (map->content[i] == 'E')
				exit++;
			i++;
		}
		i = 0;
		while(map->content[i] != '\n')
		{
			if (map->content[i] == 'C')
				collectible++;
			i++;
		}
		if (ft_strlen(map->content) != len)
		{
			printf("error\nthe map is not a rectangle");
			return (-1);
		}
		if (map->content[0] != '1' || map->content[len - 2] != '1')
		{
			printf("error\nthere miss a wall around the map");
			return (-1);
		}
		height++;
	}
	i = 0;
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
	if (player != 1)
	{
		printf("error\nthere is %d player there should be only one", player);
		return (-1);
	}
	if (exit != 1)
	{
		printf("error\nthere is %d exit there should be only one", exit);
		return (-1);
	}
	if (collectible == 0)
	{
		printf("error\nthere is no collectible");
		return (-1);
	}
	return (0);
}
