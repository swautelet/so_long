/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:33:16 by swautele          #+#    #+#             */
/*   Updated: 2022/02/23 16:49:53 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_pixel {
	int	x;
	int	y;
	int	color;
}	t_pixel;

int	draw(t_list *map)
{
	void	*video_ptr;
	void	*win_ptr;
	void	*floor;
	void	*wall;
	int		size;
	size_t	i;
	int		j;

	size = 64;
	i = 0;
	j = 0;
	video_ptr = mlx_init();
	win_ptr = mlx_new_window(video_ptr, (ft_strlen(map->content) - 1) * size, ft_lstsize(map) * size, "so_long");
	floor = mlx_xpm_file_to_image(video_ptr, "./sprite/floor.xpm", &size, &size);
	wall = mlx_xpm_file_to_image(video_ptr, "./sprite/wall.xpm", &size, &size);
	while (i < ft_strlen(map->content) - 1)
	{
		mlx_put_image_to_window(video_ptr, win_ptr, wall, size * i, size * j);
		i++;
	}
	while (map->next)
	{
		i = 0;
		j++;
		map = map->next;
		while (i < ft_strlen(map->content) - 1)
		{
			if (map->content[i] == '1')
				mlx_put_image_to_window(video_ptr, win_ptr, wall, size * i, size * j);
			if (map->content[i] == '0' || map->content[i] == 'C' || map->content[i] == 'P')
				mlx_put_image_to_window(video_ptr, win_ptr, floor, size * i, size * j);
			i++;
		}
	}
	mlx_loop(video_ptr);
	return (0);
}
