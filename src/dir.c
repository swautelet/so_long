/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:00:45 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 19:01:12 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_img *dt)
{
	int	check;

	check = ft_authorized(dt, 0, -1);
	if (check == 0)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->floor,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door,
				dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_b1,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_UP;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door,
				dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->pos_y--;
		mlx_put_image_to_window(dt->video, dt->win, dt->player_p_b,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_UP2;
	}
}

void	move_left(t_img *dt)
{
	int	check;

	check = ft_authorized(dt, -1, 0);
	if (check == 0)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->floor,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door,
				dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_l1,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_LEFT;
		dt->pos_x--;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door,
				dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_p_l,
			(dt->pos_x - 1) * 64, dt->pos_y * 64);
		dt->dir = DIR_LEFT;
		dt->pos_x--;
	}
}

void	move_down(t_img *dt)
{
	int	check;

	check = ft_authorized(dt, 0, 1);
	if (check == 0)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->floor,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door,
				dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_f1,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_DOWN;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door,
				dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->pos_y++;
		mlx_put_image_to_window(dt->video, dt->win, dt->player_p_f,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_DOWN2;
	}
}

void	move_right(t_img *dt)
{
	int	check;

	check = ft_authorized(dt, 1, 0);
	if (check == 0)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->floor,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door,
				dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_r1,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_RIGHT;
		dt->pos_x++;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor,
			dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door,
				dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_p_r,
			(dt->pos_x + 1) * 64, dt->pos_y * 64);
		dt->dir = DIR_RIGHT;
		dt->pos_x++;
	}
}
