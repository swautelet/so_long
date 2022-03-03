/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:31:31 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 16:48:23 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyplan(int keycode, t_img *dt)
{
	if (keycode == 53)
		ft_exit(dt);
	if (keycode == 13 && dt->pos_y > 1)
		move_up(dt);
	if (keycode == 0 && dt->pos_x > 0)
		move_left(dt);
	if (keycode == 1)
		move_down(dt);
	if (keycode == 2)
		move_right(dt);
	return (0);
}

int	ft_exit(t_img *dt)
{
	ft_lstclear(&dt->map, free);
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
	mlx_destroy_image(dt->video, dt->player_b);
	mlx_destroy_image(dt->video, dt->player_b1);
	mlx_destroy_image(dt->video, dt->player_b2);
	mlx_destroy_image(dt->video, dt->player_f2);
	mlx_destroy_image(dt->video, dt->player_f1);
	mlx_destroy_image(dt->video, dt->player_l);
	mlx_destroy_image(dt->video, dt->player_l1);
	mlx_destroy_image(dt->video, dt->player_p_b);
	mlx_destroy_image(dt->video, dt->player_p_f);
	mlx_destroy_image(dt->video, dt->player_p_r);
	mlx_destroy_image(dt->video, dt->player_p_l);
	mlx_destroy_image(dt->video, dt->player_r);
	mlx_destroy_image(dt->video, dt->player_r1);
	mlx_destroy_image(dt->video, dt->wall);
	mlx_destroy_image(dt->video, dt->floor);
	mlx_destroy_window(dt->video, dt->win);
	free(dt);
	exit(0);
}

void	move_up(t_img *dt)
{
	int	check;

	check = ft_authorized(dt, DIR_UP);
	if (check == 0)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_b1, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_UP;
		dt->pos_y--;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->pos_y--;
		mlx_put_image_to_window(dt->video, dt->win, dt->player_p_b, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_UP2;
		dt->pos_y--;
	}
}

void	move_left(t_img *dt)
{
	int	check;

	check = ft_authorized(dt, DIR_LEFT);
	if (check == 0)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_l1, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_LEFT;
		dt->pos_x--;

	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_p_l, (dt->pos_x - 1) * 64, dt->pos_y * 64);
		dt->dir = DIR_LEFT;
		dt->pos_x--;
	}
}

void	move_down(t_img *dt)
{
	int	check;

	check = ft_authorized(dt, DIR_DOWN);
	if (check == 0)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_f1, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_DOWN;
		dt->pos_y++;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->pos_y++;
		mlx_put_image_to_window(dt->video, dt->win, dt->player_p_f, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_DOWN2;
		dt->pos_y++;
	}
}

void	move_right(t_img *dt)
{
	int	check;

	check = ft_authorized(dt, DIR_RIGHT);
	if (check == 0)
	{
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_r1, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_RIGHT;
		dt->pos_x++;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_p_r, (dt->pos_x + 1) * 64, dt->pos_y * 64);
		dt->dir = DIR_RIGHT;
		dt->pos_x++;
	}
}
