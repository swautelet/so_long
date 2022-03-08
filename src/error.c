/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:08 by swautele          #+#    #+#             */
/*   Updated: 2022/03/08 12:00:45 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	return (-1);
}

int	ft_error(int argc, char **argv)
{
	size_t	i;

	i = ft_strlen(argv[1]);
	i -= 1;
	if (argc < 2)
		return (error_msg("Error\nTheres's no map\n"));
	if (argc > 2)
		return (error_msg("Error\nThere's too much map\n"));
	if (argv[1][i] != 'r' || argv[1][i - 1] != 'e' ||
		argv[1][i - 2] != 'b' || argv[1][i - 3] != '.')
		return (error_msg("Error\nThe map is in the wrong format\n"));
	return (0);
}

static int	count_error(t_check check)
{
	if (check.len < 3 || check.height < 3)
		return (error_msg("Error\nThe map is too short\n"));
	if (check.player != 1)
		return (error_msg("Error\nThere should be one player\n"));
	if (check.exit != 1)
		return (error_msg("Error\nThere should be one exit\n"));
	if (check.collectible == 0)
		return (error_msg("Error\nThere is no collectible\n"));
	if (check.len > 42 || check.height > 21)
		return (error_msg("Error\nThe map is too big for the screen\n"));
	return (0);
}

static int	is_a_wall(t_list *map, t_check check)
{
	check.i = 0;
	while (map->content[check.i] != '\n')
	{
		if (map->content[check.i] != '1')
			return (error_msg("error\nThere miss a wall around the map\n"));
		check.i++;
	}
	while (map->next != NULL)
	{
		check.i = 0;
		map = map->next;
		if (ft_strlen(map->content) != check.len)
			return (error_msg("Error\nThe map is not a rectangle\n"));
		if (map->content[0] != '1' || map->content[check.len - 2] != '1')
			return (error_msg("Error\nThere miss a wall around the map\n"));
	}
	check.i = 0;
	while (map->content[check.i] != '\n')
	{
		if (map->content[check.i] != '1')
			return (error_msg("error\nThere miss a wall around the map\n"));
		check.i++;
	}
	return (0);
}

int	map_error(t_list *map)
{
	t_check	check;

	check.exit = 0;
	check.player = 0;
	check.collectible = 0;
	check.len = ft_strlen(map->content);
	if (is_a_wall(map, check) == -1)
		return (-1);
	check.height = ft_lstsize(map);
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
	}
	return (count_error(check));
}
