/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:31:31 by swautele          #+#    #+#             */
/*   Updated: 2022/03/01 18:00:36 by swautele         ###   ########.fr       */
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
	free(sprite);
	exit(0);
}

static void wait_for(unsigned long long time)
{
	return ;
	usleep(time);
}

void	move_up(t_img *sprite)
{
	clock_t	start;
	clock_t	now;

	start = clock();
	now = start - clock();
	printf("now %lu\n", now);
	if (ft_authorized(sprite, DIR_UP) == 0)
	{
		while (now < ANIM_WAIT * 4)
		{
			now = start - clock();
			if (now < ANIM_WAIT * 1)
			{
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
				if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_b1, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
			}
			if (now < ANIM_WAIT * 1)
			{
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
				if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
				sprite->pos_y--;
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_b2, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
			}
			if (now < ANIM_WAIT * 1)
			{
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
				if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
				mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_b, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
			}
		}
		sprite->move++;
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y && sprite->flag == 0)
		{
			printf("you won in %dmoves GG\n", sprite->move);
			ft_exit(sprite);
		}
		else
			printf("you moved %d times\n", sprite->move);
	}
}

void	move_left(t_img *sprite)
{
	if (ft_authorized(sprite, DIR_LEFT) == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_l1, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		wait_for(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_x--;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_l, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->move++;
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y && sprite->flag == 0)
		{
			printf("you won in %dmoves GG\n", sprite->move);
			ft_exit(sprite);
		}
		else
			printf("you moved %d times\n", sprite->move);
	}
}

void	move_down(t_img *sprite)
{
	if (ft_authorized(sprite, DIR_DOWN) == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_f1, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		wait_for(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_y++;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_f2, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		wait_for(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->move++;
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y && sprite->flag == 0)
		{
			printf("you won in %dmoves GG\n", sprite->move);
			ft_exit(sprite);
		}
		else
			printf("you moved %d times\n", sprite->move);
	}
}

void	move_right(t_img *sprite)
{
	if (ft_authorized(sprite, DIR_RIGHT) == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_r1, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		wait_for(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_x++;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_r, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->move++;
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y && sprite->flag == 0)
		{
			printf("you won in %dmoves GG\n", sprite->move);
			ft_exit(sprite);
		}
		else
			printf("you moved %d times\n", sprite->move);
		
	}
}
