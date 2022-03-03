/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:08 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 20:08:03 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (-1);
}

int	ft_error(int argc, char **argv)
{
	char	*ext;

	ext = ".ber";
	if (argc < 2)
		return (error_msg("error\nTheres's no map\n"));
	if (argc > 2)
		return (error_msg("error\nthere's too much map\n"));
	if (ft_strncmp(ft_strnstr(argv[1], ".ber", SIZE_T_MAX), ext, 4) != 0)
		return (error_msg("error\nthe map is in the wrong format\n"));
	return (0);
}

static int	count_error(t_check check)
{
	if (check.len < 3 || check.height < 3)
		return (error_msg("Error\nthe map is too short\n"));
	if (check.player != 1)
		return (error_msg("Error\nthere should be only one player\n"));
	if (check.exit != 1)
		return (error_msg("Error\nthere should be only one exit\n"));
	if (check.collectible == 0)
		return (error_msg("Error\nthere is no collectible\n"));
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
			return (error_msg("error\nthere miss a wall around the map\n"));
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
			return (error_msg("Error\nthe map is not a rectangle\n"));
		if (map->content[0] != '1' || map->content[check.len - 2] != '1')
			return (error_msg("Error\nthere miss a wall around the map\n"));
		check.height++;
	}
	check.i = 0;
	while (map->content[check.i] != '\n')
	{
		if (map->content[check.i] != '1')
			return (error_msg("Error\nthere miss a wall around the map\n"));
		check.i++;
	}
	return (count_error(check));
}
