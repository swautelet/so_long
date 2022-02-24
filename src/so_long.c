/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:30 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 18:52:00 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list_c	*map;
	t_list_c	*next;

	if (ft_error(argc, argv) == -1)
		return (-1);
	map = map_reader(argv[1]);
	if (map_error(map) == -1)
	{
		ft_lstclear_c(&map, &free);
		return (-1);
	}
	next = map;
	printf("%s", next->content);
	while (next->next)
	{
		next = next->next;
		printf("%s", next->content);
	}
	init_sprite(map);
	ft_lstclear_c(&map, &free);
	return (0);
}
