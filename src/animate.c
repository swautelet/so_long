/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:11:16 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 16:53:40 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate(t_img *dt)
{
	if (dt->dir == DIR_RIGHT)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, (dt->pos_x - 1) * dt->siz, dt->pos_y * dt->siz);
		if ((dt->pos_x - 1) == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, (dt->pos_x - 1) * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_r, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->move++;
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y && dt->flag == 0)
		{
			printf("You won in %d moves GG.\nYou can walk Loki now.\n", dt->move);
			ft_exit(dt);
		}
		else
			printmove(dt);
		dt->dir = PAUSE;
	}
	else if (dt->dir == DIR_DOWN)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->pos_y++;
		mlx_put_image_to_window(dt->video, dt->win, dt->player_f2, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_DOWN2;
	}
	else if (dt->dir == DIR_DOWN2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->move++;
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y && dt->flag == 0)
		{
			printf("You won in %d moves GG.\nYou can walk Loki now.\n", dt->move);
			ft_exit(dt);
		}
		else
			printmove(dt);
		dt->dir = PAUSE;
	}
	else if (dt->dir == DIR_LEFT)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, (dt->pos_x + 1) * dt->siz, dt->pos_y * dt->siz);
		if ((dt->pos_x + 1) == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, (dt->pos_x + 1) * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_l, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->move++;
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y && dt->flag == 0)
		{
			printf("You won in %d moves GG.\nYou can walk Loki now.\n", dt->move);
			ft_exit(dt);
		}
		else
			printmove(dt);
		dt->dir = PAUSE;
	}
	else if (dt->dir == DIR_UP)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->pos_y--;
		mlx_put_image_to_window(dt->video, dt->win, dt->player_b2, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->dir = DIR_UP2;
	}
	else if (dt->dir == DIR_UP2)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(dt->video, dt->win, dt->floor, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
			mlx_put_image_to_window(dt->video, dt->win, dt->door, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		mlx_put_image_to_window(dt->video, dt->win, dt->player_b, dt->pos_x * dt->siz, dt->pos_y * dt->siz);
		dt->move++;
		if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y && dt->flag == 0)
		{
			printf("You won in %d moves GG.\nYou can walk Loki now.\n", dt->move);
			ft_exit(dt);
		}
		else
			printmove(dt);
		dt->dir = PAUSE;
	}
	return (0);
}
