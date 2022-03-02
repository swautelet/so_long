/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:31:31 by swautele          #+#    #+#             */
/*   Updated: 2022/03/02 19:12:24 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyplan(int keycode, t_img *sprite)
{
	if (keycode == 53)
		ft_exit(sprite);
	if (keycode == 13 && sprite->pos_y > 1)
		move_up(sprite);
	if (keycode == 0 && sprite->pos_x > 0)
		move_left(sprite);
	if (keycode == 1)
		move_down(sprite);
	if (keycode == 2)
		move_right(sprite);
	return (0);
}

int	ft_exit(t_img *sprite)
{
	ft_lstclear_c(&sprite->map, free);
	mlx_destroy_image(sprite->video, sprite->leash);
	mlx_destroy_image(sprite->video, sprite->collar);
	mlx_destroy_image(sprite->video, sprite->boot);
	mlx_destroy_image(sprite->video, sprite->poopbag);
	mlx_destroy_image(sprite->video, sprite->key);
	mlx_destroy_image(sprite->video, sprite->player);
	mlx_destroy_image(sprite->video, sprite->loki);
	mlx_destroy_image(sprite->video, sprite->door);
	mlx_destroy_image(sprite->video, sprite->door_o);
	mlx_destroy_image(sprite->video, sprite->opal);
	mlx_destroy_image(sprite->video, sprite->player_b);
	mlx_destroy_image(sprite->video, sprite->player_b1);
	mlx_destroy_image(sprite->video, sprite->player_b2);
	mlx_destroy_image(sprite->video, sprite->player_f2);
	mlx_destroy_image(sprite->video, sprite->player_f1);
	mlx_destroy_image(sprite->video, sprite->player_l);
	mlx_destroy_image(sprite->video, sprite->player_l1);
	mlx_destroy_image(sprite->video, sprite->player_p_b);
	mlx_destroy_image(sprite->video, sprite->player_p_f);
	mlx_destroy_image(sprite->video, sprite->player_p_r);
	mlx_destroy_image(sprite->video, sprite->player_p_l);
	mlx_destroy_image(sprite->video, sprite->player_r);
	mlx_destroy_image(sprite->video, sprite->player_r1);
	mlx_destroy_image(sprite->video, sprite->wall);
	mlx_destroy_image(sprite->video, sprite->floor);
	mlx_destroy_window(sprite->video, sprite->win);
	free(sprite);
	exit(0);
}

void	move_up(t_img *sprite)
{
	int	check;

	check = ft_authorized(sprite, DIR_UP);
	if (check == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_b1, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->dir = DIR_UP;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_y--;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_p_b, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->dir = DIR_UP2;
	}
}

void	move_left(t_img *sprite)
{
	int	check;

	check = ft_authorized(sprite, DIR_LEFT);
	if (check == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_l1, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->dir = DIR_LEFT;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_p_l, (sprite->pos_x - 1) * 64, sprite->pos_y * 64);
		sprite->dir = DIR_LEFT;
	}
}

void	move_down(t_img *sprite)
{
	int	check;

	check = ft_authorized(sprite, DIR_DOWN);
	if (check == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_f1, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->dir = DIR_DOWN;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_y++;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_p_f, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->dir = DIR_DOWN2;
	}
}

void	move_right(t_img *sprite)
{
	int	check;

	check = ft_authorized(sprite, DIR_RIGHT);
	if (check == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_r1, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->dir = DIR_RIGHT;
	}
	if (check == 2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_p_r, (sprite->pos_x + 1) * 64, sprite->pos_y * 64);
		sprite->dir = DIR_RIGHT;
	}
}
