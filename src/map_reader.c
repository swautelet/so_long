/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:02:17 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 18:52:59 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*map_reader(char *name)
{
	t_reader	read;

	read.i = 0;
	read.fd = open(name, O_RDONLY);
	read.line = get_next_line(read.fd);
	read.map = ft_lstnew(read.line);
	read.map->line = read.i;
	while (read.line)
	{
		read.line = get_next_line(read.fd);
		read.i++;
		if (read.line != NULL)
		{
			read.new = ft_lstnew(read.line);
			if (read.new == NULL)
			{
				free(read.line);
				return (read.map);
			}
			read.new->line = read.i;
			ft_lstadd_back(&read.map, read.new);
		}
	}
	close(read.fd);
	return (read.map);
}
