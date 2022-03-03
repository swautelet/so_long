/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:11:16 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 19:17:07 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sub_animate_end(t_img *dt)
{
	if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y && dt->flag == 0)
	{
		printf("You won in %d moves GG.\nYou can walk Loki now.\n", dt->move);
		ft_exit(dt);
	}
	else
		printmove(dt);
	if (dt->dir == DIR_RIGHT || dt->dir == DIR_LEFT
		|| dt->dir == DIR_DOWN2 || dt->dir == DIR_UP2)
		dt->dir = PAUSE;
	if (dt->dir == DIR_UP)
		dt->dir = DIR_UP2;
	if (dt->dir == DIR_DOWN)
		dt->dir = DIR_DOWN2;
}

static void	sub_animate(t_img *dt, int off, void *player, int posy_inc)
{
	usleep(ANIM_WAIT);
	mlx_put_image_to_window(dt->video, dt->win, dt->floor,
		(dt->pos_x - off) * dt->s, dt->pos_y * dt->s);
	if ((dt->pos_x - off) == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
		mlx_put_image_to_window(dt->video, dt->win, dt->door,
			(dt->pos_x - off) * dt->s, dt->pos_y * dt->s);
	mlx_put_image_to_window(dt->video, dt->win, dt->floor,
		dt->pos_x * dt->s, dt->pos_y * dt->s);
	if (dt->pos_x == dt->pos_d_x && dt->pos_y == dt->pos_d_y)
		mlx_put_image_to_window(dt->video, dt->win, dt->door,
			dt->pos_x * dt->s, dt->pos_y * dt->s);
	dt->pos_y += posy_inc;
	mlx_put_image_to_window(dt->video, dt->win, player,
		dt->pos_x * dt->s, dt->pos_y * dt->s);
	if (dt->dir != DIR_DOWN2 && dt->dir != DIR_UP2)
		dt->move++;
	sub_animate_end(dt);
}

int	animate(t_img *dt)
{
	if (dt->dir == DIR_RIGHT)
		sub_animate(dt, 1, dt->pl_r, 0);
	else if (dt->dir == DIR_LEFT)
		sub_animate(dt, -1, dt->pl_l, 0);
	else if (dt->dir == DIR_UP)
		sub_animate(dt, 0, dt->pl_b2, -1);
	else if (dt->dir == DIR_DOWN)
		sub_animate(dt, 0, dt->pl_f2, 1);
	else if (dt->dir == DIR_DOWN2)
		sub_animate(dt, 0, dt->player, 0);
	else if (dt->dir == DIR_UP2)
		sub_animate(dt, 0, dt->pl_b, 0);
	if (dt->dir != DIR_UP && dt->dir != DIR_DOWN)
		dt->done = 0;
	return (0);
}
