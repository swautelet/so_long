/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:33:16 by swautele          #+#    #+#             */
/*   Updated: 2022/02/28 17:56:23 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_sprite(t_list_c *map)
{
	t_img	*sprite;
	t_img	fuck;

	sprite = &fuck;
	sprite->size = 64;
	sprite->flag = 0;
	sprite->video = mlx_init();
	sprite->win = mlx_new_window(sprite->video, (ft_strlen(map->content) - 1) * sprite->size, ft_lstsize_c(map) * sprite->size, "so_long");
	sprite->leash = mlx_xpm_file_to_image(sprite->video, "./sprite/leash_.xpm", &sprite->size, &sprite->size);
	sprite->collar = mlx_xpm_file_to_image(sprite->video, "./sprite/collar_.xpm", &sprite->size, &sprite->size);
	sprite->boot = mlx_xpm_file_to_image(sprite->video, "./sprite/boot_.xpm", &sprite->size, &sprite->size);
	sprite->poopbag = mlx_xpm_file_to_image(sprite->video, "./sprite/poopbag.xpm", &sprite->size, &sprite->size);
	sprite->key = mlx_xpm_file_to_image(sprite->video, "./sprite/key_.xpm", &sprite->size, &sprite->size);
	sprite->player = mlx_xpm_file_to_image(sprite->video, "./sprite/player.xpm", &sprite->size, &sprite->size);
	sprite->loki = mlx_xpm_file_to_image(sprite->video, "./sprite/loki.xpm", &sprite->size, &sprite->size);
	sprite->door = mlx_xpm_file_to_image(sprite->video, "./sprite/door.xpm", &sprite->size, &sprite->size);
	sprite->door_o = mlx_xpm_file_to_image(sprite->video, "./sprite/door_o.xpm", &sprite->size, &sprite->size);
	sprite->wall = mlx_xpm_file_to_image(sprite->video, "./sprite/wall_a.xpm", &sprite->size, &sprite->size);
	sprite->floor = mlx_xpm_file_to_image(sprite->video, "./sprite/floor.xpm", &sprite->size, &sprite->size);
	sprite->move = 0;
	return (draw(map, sprite));
}

int	draw(t_list_c *map, t_img *sprite)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	sprite->map = map;
	while (i < ft_strlen(map->content) - 1)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->wall, sprite->size * i, sprite->size * j);
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
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->wall, 64 * i, 64 * j);
			if (map->content[i] == '0' || map->content[i] == 'C' || map->content[i] == 'P' || map->content[i] == 'E')
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, 64 * i, 64 * j);
			if (map->content[i] == 'P')
			{
				sprite->pos_x = i;
				sprite->pos_y = j;
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->player, 64 * i, 64 * j);
			}
			if (map->content[i] == 'E')
			{
				sprite->pos_d_x = i;
				sprite->pos_d_y = j;
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, 64 * i, 64 * j);
			}
			if (map->content[i] == 'C' && sprite->flag == 0)
			{
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->boot, 64 * i, 64 * j);
				sprite->flag++;
			}
			else if (map->content[i] == 'C' && sprite->flag == 1)
			{
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->collar, 64 * i, 64 * j);
				sprite->flag++;
			}
			else if (map->content[i] == 'C' && sprite->flag == 2)
			{
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->leash, 64 * i, 64 * j);
				sprite->flag++;
			}
			else if (map->content[i] == 'C' && sprite->flag == 3)
			{
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->poopbag, 64 * i, 64 * j);
				sprite->flag++;
			}
			else if (map->content[i] == 'C' && sprite->flag >= 4)
			{
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->key, 64 * i, 64 * j);
				sprite->flag++;
			}
			i++;
		}
	}
	mlx_hook(sprite->win, 02, 1L<<0, keyplan, sprite);
	mlx_hook(sprite->win, 17, 1L<<5, ft_exit, map);
	mlx_loop(sprite->video);
	return (0);
}
