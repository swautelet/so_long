/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:02:17 by swautele          #+#    #+#             */
/*   Updated: 2022/02/22 21:00:14 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*map_reader(char *name)
{
	int		fd;
	char	*line;
	t_list	*map;
	t_list	*new;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	map = ft_lstnew(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			new = ft_lstnew(line);
			if (new == NULL)
			{
				free(line);
				return (map);
			}
			ft_lstadd_back(&map, new);
		}
	}
	close(fd);
	return (map);
}
