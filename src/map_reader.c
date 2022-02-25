/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:02:17 by swautele          #+#    #+#             */
/*   Updated: 2022/02/25 14:38:33 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list_c	*map_reader(char *name)
{
	int			fd;
	char		*line;
	t_list_c	*map;
	t_list_c	*new;
	int			i;

	i = 0;
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	map = ft_lstnew_c(line);
	map->line = i;
	while (line)
	{
		line = get_next_line(fd);
		i++;
		if (line != NULL)
		{
			new = ft_lstnew_c(line);
			if (new == NULL)
			{
				free(line);
				return (map);
			}
			new->line = i;
			ft_lstadd_back_c(&map, new);
		}
	}
	close(fd);
	return (map);
}
