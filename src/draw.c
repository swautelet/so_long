/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:33:16 by swautele          #+#    #+#             */
/*   Updated: 2022/02/18 14:43:03 by swautele         ###   ########.fr       */
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

int	draw(void)
{
	void	*video_ptr;
	void	*win_ptr;
//	t_data	*img;
//	t_pixel	*draw;
	int		x;
	int		y;
	int		color;

	video_ptr = mlx_init();
	win_ptr = mlx_new_window(video_ptr, 500, 500, "test");
//	img->img = mlx_new_image(video_ptr, 500, 500);
//	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixels, &img->line_lenght, &img->endian);
	x = 10;
	y = 10;
	color = 0xffffff;
	while(x <= 100)
	{
		mlx_pixel_put(video_ptr, win_ptr, x, y, color);
//		mlx_string_put(video_ptr, win_ptr, x, y, color, "what the fuck?");
		y++;
		if (y >= 100)
		{
			y = 10;
			x++;
		}
	}
//	mlx_put_image_to_window(video_ptr, win_ptr, img->addr, 0, 0);
	mlx_loop(video_ptr);
	return(0);
}
