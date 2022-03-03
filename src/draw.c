/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:33:16 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 19:22:19 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw(t_list *map, t_img *dt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dt->map = map;
	while (i < ft_strlen(map->content) - 1)
	{
		mlx_put_image_to_window(dt->video, dt->win,
			dt->wall, dt->s * i, dt->s * j);
		i++;
	}
	mlx_string_put(dt->video, dt->win, 10, 30, 0x000000, ft_itoa(dt->move));
	while (map->next)
	{
		i = 0;
		j++;
		map = map->next;
		while (i < ft_strlen(map->content) - 1)
		{
			if (map->content[i] == '1')
				mlx_put_image_to_window(dt->video, dt->win,
					dt->wall, 64 * i, 64 * j);
			else
				mlx_put_image_to_window(dt->video, dt->win,
					dt->floor, 64 * i, 64 * j);
			if (map->content[i] == 'P')
			{
				dt->pos_x = i;
				dt->pos_y = j;
				mlx_put_image_to_window(dt->video, dt->win,
					dt->player, 64 * i, 64 * j);
			}
			if (map->content[i] == 'E')
			{
				dt->pos_d_x = i;
				dt->pos_d_y = j;
				mlx_put_image_to_window(dt->video, dt->win,
					dt->door, 64 * i, 64 * j);
			}
			if (map->content[i] == 'N')
				mlx_put_image_to_window(dt->video, dt->win,
					dt->opal, 64 * i, 64 * j);
			if (map->content[i] == 'C' && dt->flag == 0)
			{
				mlx_put_image_to_window(dt->video, dt->win,
					dt->loki, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag == 1)
			{
				mlx_put_image_to_window(dt->video, dt->win,
					dt->boot, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag == 2)
			{
				mlx_put_image_to_window(dt->video, dt->win,
					dt->collar, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag == 3)
			{
				mlx_put_image_to_window(dt->video, dt->win,
					dt->leash, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag == 4)
			{
				mlx_put_image_to_window(dt->video, dt->win,
					dt->key, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag >= 5)
			{
				mlx_put_image_to_window(dt->video, dt->win,
					dt->poopbag, 64 * i, 64 * j);
				dt->flag++;
			}
			i++;
		}
	}
	dt->done = 0;
	mlx_loop_hook(dt->video, animate, dt);
	mlx_hook(dt->win, 02, 1L<<0, keyplan, dt);
	mlx_hook(dt->win, 17, 1L<<5, ft_exit, dt);
	mlx_loop(dt->video);
	return (0);
}
