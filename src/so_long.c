/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:30 by swautele          #+#    #+#             */
/*   Updated: 2022/02/22 16:42:31 by swautele         ###   ########.fr       */
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
	next = map;
	while(next->content)
	{
		printf("%s", next->content);
		next = next->next;
	}
	ft_lstclear(&map, &free);
	return (0);
}
