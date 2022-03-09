/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:02:17 by swautele          #+#    #+#             */
/*   Updated: 2022/03/09 15:13:49 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_reader	reader_init(char *name)
{
	t_reader	read;

	read.i = 0;
	read.fd = open(name, O_RDONLY);
	if (read.fd < 0)
		exit (error_msg("Error\nCan't open the map"));
	read.line = get_next_line(read.fd);
	read.map = ft_lstnew(read.line);
	read.map->line = read.i;
	return (read);
}

t_list	*map_reader(char *name)
{
	t_reader	read;

	read = reader_init(name);
	while (read.line)
	{
		read.line = get_next_line(read.fd);
		if (read.line != NULL)
		{
			read.new = ft_lstnew(read.line);
			if (read.new == NULL)
			{
				free(read.line);
				return (read.map);
			}
			read.new->line = ++read.i;
			ft_lstadd_back(&read.map, read.new);
		}
	}
	close(read.fd);
	return (read.map);
}
