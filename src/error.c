/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:08 by swautele          #+#    #+#             */
/*   Updated: 2022/02/22 16:25:33 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int argc, char **argv)
{
	char	*ext;

	ext = ".ber";
	if (argc < 2)
	{
		printf("error\nTheres's no map");
		return (-1);
	}
	if (argc > 2)
	{
		printf("error\nthere's too much map");
		return (-1);
	}
	if (ft_strncmp(ft_strnstr(argv[1], ".ber", SIZE_T_MAX), ext, 4) != 0)
	{
		printf("error\nthe map is in the wrong format");
		return (-1);
	}
	return (0);
}
