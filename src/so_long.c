/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:30 by swautele          #+#    #+#             */
/*   Updated: 2022/03/08 12:02:41 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list	*map;
	t_list	*next;

	if (ft_error(argc, argv) == -1)
		return (-1);
	map = map_reader(argv[1]);
	if (map->content == NULL)
		return (error_msg("Error\nThe map is empty\n"));
	if (map_error(map) == -1)
	{
		ft_lstclear(&map, &free);
		return (-1);
	}
	next = map;
	init_sprite(map);
	ft_lstclear(&map, &free);
	return (0);
}
