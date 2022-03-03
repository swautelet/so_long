/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:31:31 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 21:47:58 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyplan(int keycode, t_img *dt)
{
	if (keycode == 53)
		ft_exit(dt);
	if (dt->done != 0)
		return (0);
	dt->done++;
	if (keycode == 13 || keycode == 126)
		move_up(dt);
	if (keycode == 0 || keycode == 123)
		move_left(dt);
	if (keycode == 1 || keycode == 125)
		move_down(dt);
	if (keycode == 2 || keycode == 124)
		move_right(dt);
	return (0);
}

static void	destroy_image(t_img *dt)
{
	mlx_destroy_image(dt->video, dt->leash);
	mlx_destroy_image(dt->video, dt->collar);
	mlx_destroy_image(dt->video, dt->boot);
	mlx_destroy_image(dt->video, dt->poopbag);
	mlx_destroy_image(dt->video, dt->key);
	mlx_destroy_image(dt->video, dt->player);
	mlx_destroy_image(dt->video, dt->loki);
	mlx_destroy_image(dt->video, dt->door);
	mlx_destroy_image(dt->video, dt->door_o);
	mlx_destroy_image(dt->video, dt->opal);
	mlx_destroy_image(dt->video, dt->pl_b);
	mlx_destroy_image(dt->video, dt->pl_b1);
	mlx_destroy_image(dt->video, dt->pl_b2);
	mlx_destroy_image(dt->video, dt->pl_f2);
	mlx_destroy_image(dt->video, dt->pl_f1);
	mlx_destroy_image(dt->video, dt->pl_l);
	mlx_destroy_image(dt->video, dt->pl_l1);
	mlx_destroy_image(dt->video, dt->pl_p_b);
	mlx_destroy_image(dt->video, dt->pl_p_f);
	mlx_destroy_image(dt->video, dt->pl_p_r);
	mlx_destroy_image(dt->video, dt->pl_p_l);
	mlx_destroy_image(dt->video, dt->pl_r);
	mlx_destroy_image(dt->video, dt->pl_r1);
	mlx_destroy_image(dt->video, dt->wall);
	mlx_destroy_image(dt->video, dt->floor);
}

int	ft_exit(t_img *dt)
{
	ft_lstclear(&dt->map, free);
	destroy_image(dt);
	mlx_destroy_window(dt->video, dt->win);
	free(dt);
	exit(0);
}
