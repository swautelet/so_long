/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:30:08 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 18:35:06 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_door(t_img *dt)
{
	mlx_put_image_to_window(dt->video, dt->win, dt->floor,
		dt->pos_d_x * dt->siz, dt->pos_d_y * dt->siz);
	mlx_put_image_to_window(dt->video, dt->win, dt->door_o,
		dt->pos_d_x * dt->siz, dt->pos_d_y * dt->siz);
}

int	ft_authorized(t_img *dt, int x_off, int y_off)
{
	t_list	*read;

	read = dt->map;
	while (read->line < dt->pos_y + y_off)
		read = read->next;
	if (read->content[dt->pos_x + x_off] != '1')
	{
		if (read->content[dt->pos_x + x_off] == 'C')
		{
			read->content[dt->pos_x + x_off] = '0';
			dt->flag--;
			if (dt->flag == 0)
				open_door(dt);
			return (2);
		}
		if (read->content[dt->pos_x + x_off] == 'N')
		{
			printf("You lost. Opal killed you.\n");
			ft_exit(dt);
		}
		return (0);
	}
	return (1);
}

void	printmove(t_img *sprite)
{
	mlx_put_image_to_window(sprite->video,
		sprite->win, sprite->wall, 0 * 64, 0 * 64);
	mlx_string_put(sprite->video, sprite->win, 10,
		30, 0x000000, ft_itoa(sprite->move));
}
