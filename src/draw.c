/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:33:16 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:54:25 by swautele         ###   ########.fr       */
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

void	*init_list_collectible(void	*video_ptr, int size)
{
	void	*img;
	t_list_v	*list;
	t_list_v	*next;

	img = mlx_xpm_file_to_image(video_ptr, "./sprite/leash.xpm", &size, &size);
	list = ft_lstnew_v(img);
	img = mlx_xpm_file_to_image(video_ptr, "./sprite/collar.xpm", &size, &size);
	next = ft_lstnew_v(img);
	ft_lstadd_back_v(&list, next);
	img = mlx_xpm_file_to_image(video_ptr, "./sprite/boot.xpm", &size, &size);
	next = ft_lstnew_v(img);
	ft_lstadd_back_v(&list, next);
	img = mlx_xpm_file_to_image(video_ptr, "./sprite/poopbag.xpm", &size, &size);
	next = ft_lstnew_v(img);
	ft_lstadd_back_v(&list, next);
	img = mlx_xpm_file_to_image(video_ptr, "./sprite/key.xpm", &size, &size);
	next = ft_lstnew_v(img);
	ft_lstadd_back_v(&list, next);
	return (list);
}

int	draw(t_list_c *map)
{
	void		*video_ptr;
	void		*win_ptr;
	void		*floor;
	void		*wall;
	int			size;
	size_t		i;
	int			j;
	t_list_v	*collect;
	t_list_v	*read;

	size = 64;
	i = 0;
	j = 0;
	video_ptr = mlx_init();
	win_ptr = mlx_new_window(video_ptr, (ft_strlen(map->content) - 1) * size, ft_lstsize_c(map) * size, "so_long");
	floor = mlx_xpm_file_to_image(video_ptr, "./sprite/floor.xpm", &size, &size);
	wall = mlx_xpm_file_to_image(video_ptr, "./sprite/wall.xpm", &size, &size);
	collect = init_list_collectible(video_ptr, size);
	read = collect;
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
			if (map->content[i] == 'C')
			{
				mlx_put_image_to_window(video_ptr, win_ptr, read->content, size * i, size * j);
				if (read->next)
					read = read->next;
			}
			i++;
		}
	}
	ft_lstclear_v(&collect, NULL);
	mlx_loop(video_ptr);
	return (0);
}
