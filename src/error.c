/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:08 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 19:27:30 by swautele         ###   ########.fr       */
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
	t_check	check;

	check.i = 0;
	check.exit = 0;
	check.player = 0;
	check.collectible = 0;
	check.len = ft_strlen(map->content);
	while (map->content[check.i] != '\n')
	{
		if (map->content[check.i] != '1')
		{
			printf("error\nthere miss a wall around the map");
			return (-1);
		}
		check.i++;
	}
	check.height = 1;
	while (map->next != NULL)
	{
		map = map->next;
		check.i = 0;
		while (map->content[check.i] != '\n')
		{
			if (map->content[check.i] == 'P')
				check.player++;
			if (map->content[check.i] == 'E')
				check.exit++;
			if (map->content[check.i] == 'C')
				check.collectible++;
			check.i++;
		}
		if (ft_strlen(map->content) != check.len)
		{
			printf("Error\nthe map is not a rectangle");
			return (-1);
		}
		if (map->content[0] != '1' || map->content[check.len - 2] != '1')
		{
			printf("Error\nthere miss a wall around the map");
			return (-1);
		}
		check.height++;
	}
	check.i = 0;
	while (map->content[check.i] != '\n')
	{
		if (map->content[check.i] != '1')
		{
			printf("Error\nthere miss a wall around the map");
			return (-1);
		}
		check.i++;
	}
	if (check.len < 3 || check.height < 3)
	{
		printf("Error\nthe map is too short");
		return (-1);
	}
	if (check.player != 1)
	{
		printf("Error\nthere should be only one player");
		return (-1);
	}
	if (check.exit != 1)
	{
		printf("Error\nthere should be only one exit");
		return (-1);
	}
	if (check.collectible == 0)
	{
		printf("Error\nthere is no collectible");
		return (-1);
	}
	return (0);
}
