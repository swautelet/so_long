/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:21:47 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 19:22:23 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*xpm_img(void *mlx, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

static void	sub_init_sprites(t_img *d)
{
	d->leash = xpm_img(d->video, "./sprite/leash.xpm", &d->s, &d->s);
	d->collar = xpm_img(d->video, "./sprite/collar.xpm", &d->s, &d->s);
	d->boot = xpm_img(d->video, "./sprite/boot.xpm", &d->s, &d->s);
	d->poopbag = xpm_img(d->video, "./sprite/poopbag.xpm", &d->s, &d->s);
	d->key = xpm_img(d->video, "./sprite/key.xpm", &d->s, &d->s);
	d->player = xpm_img(d->video, "./sprite/player.xpm", &d->s, &d->s);
	d->loki = xpm_img(d->video, "./sprite/loki.xpm", &d->s, &d->s);
	d->door = xpm_img(d->video, "./sprite/door.xpm", &d->s, &d->s);
	d->door_o = xpm_img(d->video, "./sprite/door_o.xpm", &d->s, &d->s);
	d->opal = xpm_img(d->video, "./sprite/opal.xpm", &d->s, &d->s);
}

static void	sub_init_sprites_player(t_img *d)
{
	d->pl_b = xpm_img(d->video, "./sprite/player_b.xpm", &d->s, &d->s);
	d->pl_b1 = xpm_img(d->video, "./sprite/player_b1.xpm", &d->s, &d->s);
	d->pl_b2 = xpm_img(d->video, "./sprite/player_b2.xpm", &d->s, &d->s);
	d->pl_f2 = xpm_img(d->video, "./sprite/player_f2.xpm", &d->s, &d->s);
	d->pl_f1 = xpm_img(d->video, "./sprite/player_f1.xpm", &d->s, &d->s);
	d->pl_l = xpm_img(d->video, "./sprite/player_l.xpm", &d->s, &d->s);
	d->pl_l1 = xpm_img(d->video, "./sprite/player_l1.xpm", &d->s, &d->s);
	d->pl_p_b = xpm_img(d->video, "./sprite/player_p_b.xpm", &d->s, &d->s);
	d->pl_p_f = xpm_img(d->video, "./sprite/player_p_f.xpm", &d->s, &d->s);
	d->pl_p_r = xpm_img(d->video, "./sprite/player_p_r.xpm", &d->s, &d->s);
	d->pl_p_l = xpm_img(d->video, "./sprite/player_p_l.xpm", &d->s, &d->s);
	d->pl_r = xpm_img(d->video, "./sprite/player_r.xpm", &d->s, &d->s);
	d->pl_r1 = xpm_img(d->video, "./sprite/player_r1.xpm", &d->s, &d->s);
}

int	init_sprite(t_list *map)
{
	t_img	*dt;

	dt = malloc(sizeof(t_img));
	if (dt == NULL)
		return (-1);
	dt->s = 64;
	dt->flag = 0;
	dt->video = mlx_init();
	dt->win = mlx_new_window(dt->video, (ft_strlen(map->content) - 1) * dt->s,
			ft_lstsize(map) * dt->s, "so_long");
	sub_init_sprites(dt);
	sub_init_sprites_player(dt);
	dt->wall = xpm_img(dt->video, "./sprite/wall.xpm", &dt->s, &dt->s);
	dt->floor = xpm_img(dt->video, "./sprite/floor.xpm", &dt->s, &dt->s);
	dt->move = 0;
	return (draw(map, dt));
}
