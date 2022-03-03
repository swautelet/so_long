/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:33:16 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 17:36:18 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*xpm_img(void *mlx, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

static void	sub_init_sprites(t_img *dt)
{
	dt->leash = xpm_img(dt->video, "./sprite/leash.xpm", &dt->siz, &dt->siz);
	dt->collar = xpm_img(dt->video, "./sprite/collar.xpm", &dt->siz, &dt->siz);
	dt->boot = xpm_img(dt->video, "./sprite/boot.xpm", &dt->siz, &dt->siz);
	dt->poopbag = xpm_img(dt->video, "./sprite/poopbag.xpm", &dt->siz, &dt->siz);
	dt->key = xpm_img(dt->video, "./sprite/key.xpm", &dt->siz, &dt->siz);
	dt->player = xpm_img(dt->video, "./sprite/player.xpm", &dt->siz, &dt->siz);
	dt->loki = xpm_img(dt->video, "./sprite/loki.xpm", &dt->siz, &dt->siz);
	dt->door = xpm_img(dt->video, "./sprite/door.xpm", &dt->siz, &dt->siz);
	dt->door_o = xpm_img(dt->video, "./sprite/door_o.xpm", &dt->siz, &dt->siz);
	dt->opal = xpm_img(dt->video, "./sprite/opal.xpm", &dt->siz, &dt->siz);
}

static void	sub_init_sprites_player(t_img *dt)
{
	dt->player_b = xpm_img(dt->video, "./sprite/player_b.xpm", &dt->siz, &dt->siz);
	dt->player_b1 = xpm_img(dt->video, "./sprite/player_b1.xpm", &dt->siz, &dt->siz);
	dt->player_b2 = xpm_img(dt->video, "./sprite/player_b2.xpm", &dt->siz, &dt->siz);
	dt->player_f2 = xpm_img(dt->video, "./sprite/player_f2.xpm", &dt->siz, &dt->siz);
	dt->player_f1 = xpm_img(dt->video, "./sprite/player_f1.xpm", &dt->siz, &dt->siz);
	dt->player_l = xpm_img(dt->video, "./sprite/player_l.xpm", &dt->siz, &dt->siz);
	dt->player_l1 = xpm_img(dt->video, "./sprite/player_l1.xpm", &dt->siz, &dt->siz);
	dt->player_p_b = xpm_img(dt->video, "./sprite/player_p_b.xpm", &dt->siz, &dt->siz);
	dt->player_p_f = xpm_img(dt->video, "./sprite/player_p_f.xpm", &dt->siz, &dt->siz);
	dt->player_p_r = xpm_img(dt->video, "./sprite/player_p_r.xpm", &dt->siz, &dt->siz);
	dt->player_p_l = xpm_img(dt->video, "./sprite/player_p_l.xpm", &dt->siz, &dt->siz);
	dt->player_r = xpm_img(dt->video, "./sprite/player_r.xpm", &dt->siz, &dt->siz);
	dt->player_r1 = xpm_img(dt->video, "./sprite/player_r1.xpm", &dt->siz, &dt->siz);
}

int	init_sprite(t_list *map)
{
	t_img	*dt;

	dt = malloc(sizeof(t_img));
	if (dt == NULL)
		return (-1);
	dt->siz = 64;
	dt->flag = 0;
	dt->video = mlx_init();
	dt->win = mlx_new_window(dt->video, (ft_strlen(map->content) - 1) * dt->siz, ft_lstsize(map) * dt->siz, "so_long");
	sub_init_sprites(dt);
	sub_init_sprites_player(dt);
	dt->wall = xpm_img(dt->video, "./sprite/wall.xpm", &dt->siz, &dt->siz);
	dt->floor = xpm_img(dt->video, "./sprite/floor.xpm", &dt->siz, &dt->siz);
	dt->move = 0;
	return (draw(map, dt));
}

int	draw(t_list *map, t_img *dt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dt->map = map;
	while (i < ft_strlen(map->content) - 1)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->wall, dt->siz * i, dt->siz * j);
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
				mlx_put_image_to_window(dt->video, dt->win, dt->wall, 64 * i, 64 * j);
			if (map->content[i] == '0' || map->content[i] == 'C' || map->content[i] == 'P' || map->content[i] == 'E' || map->content[i] == 'N')
				mlx_put_image_to_window(dt->video, dt->win, dt->floor, 64 * i, 64 * j);
			if (map->content[i] == 'P')
			{
				dt->pos_x = i;
				dt->pos_y = j;
				mlx_put_image_to_window(dt->video, dt->win, dt->player, 64 * i, 64 * j);
			}
			if (map->content[i] == 'E')
			{
				dt->pos_d_x = i;
				dt->pos_d_y = j;
				mlx_put_image_to_window(dt->video, dt->win, dt->door, 64 * i, 64 * j);
			}
			if (map->content[i] == 'N')
			{
				mlx_put_image_to_window(dt->video, dt->win, dt->opal, 64 * i, 64 * j);
			}
			if (map->content[i] == 'C' && dt->flag == 0)
			{
				mlx_put_image_to_window(dt->video, dt->win, dt->loki, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag == 1)
			{
				mlx_put_image_to_window(dt->video, dt->win, dt->boot, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag == 2)
			{
				mlx_put_image_to_window(dt->video, dt->win, dt->collar, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag == 3)
			{
				mlx_put_image_to_window(dt->video, dt->win, dt->leash, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag == 4)
			{
				mlx_put_image_to_window(dt->video, dt->win, dt->key, 64 * i, 64 * j);
				dt->flag++;
			}
			else if (map->content[i] == 'C' && dt->flag >= 5)
			{
				mlx_put_image_to_window(dt->video, dt->win, dt->poopbag, 64 * i, 64 * j);
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
