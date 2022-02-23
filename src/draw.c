/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:33:16 by swautele          #+#    #+#             */
/*   Updated: 2022/02/23 14:33:14 by swautele         ###   ########.fr       */
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
	void	*img;
	int		i;
	(void)	map;

	i = 50;
	video_ptr = mlx_init();
	win_ptr = mlx_new_window(video_ptr, 500, 500, "test");
	img = mlx_xpm_file_to_image(video_ptr, "./sprite/floor.xpm", &i, &i);
	mlx_put_image_to_window(video_ptr, win_ptr, img, 0, 0);
	mlx_loop(video_ptr);
	return (0);
}
