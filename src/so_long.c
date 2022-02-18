/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:27:05 by simonwautel       #+#    #+#             */
/*   Updated: 2022/02/18 22:27:29 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (ft_error(argc, argv) == -1)
		return (-1);
	map = map_reader(argv[1]);
	if (map == NULL)
		return (-1);
	return (0);
}
