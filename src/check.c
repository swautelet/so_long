/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:30:08 by swautele          #+#    #+#             */
/*   Updated: 2022/03/01 15:50:46 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_authorized(t_img *sprite, char str)
{
	t_list_c	*read;

	read = sprite->map;
	if (str == DIR_UP)
	{
		while (read->line < (sprite->pos_y) - 1)
		{
			read = read->next;
		}
		if (read->content[sprite->pos_x] != '1')
		{
			if (read->content[sprite->pos_x] == 'C')
			{
				read->content[sprite->pos_x] = '0';
				sprite->flag--;
				if (sprite->flag == 0)
				{
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_d_x * sprite->size, sprite->pos_d_y * sprite->size);
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door_o, sprite->pos_d_x * sprite->size, sprite->pos_d_y * sprite->size);
				}
			}
			return (0);
		}
	}
	else if (str == DIR_LEFT)
	{
		while (read->line < sprite->pos_y)
			read = read->next;
		if (read->content[sprite->pos_x - 1] != '1')
		{
			if (read->content[sprite->pos_x - 1] == 'C')
			{
				read->content[sprite->pos_x - 1] = '0';
				sprite->flag--;
				if (sprite->flag == 0)
				{
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_d_x * sprite->size, sprite->pos_d_y * sprite->size);
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door_o, sprite->pos_d_x * sprite->size, sprite->pos_d_y * sprite->size);
				}
			}
			return (0);
		}
	}
	else if (str == DIR_DOWN)
	{
		while (read->line <= sprite->pos_y)
			read = read->next;
		if (read->content[sprite->pos_x] != '1')
		{
			if (read->content[sprite->pos_x] == 'C')
			{
				read->content[sprite->pos_x] = '0';
				sprite->flag--;
				if (sprite->flag == 0)
				{
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_d_x * sprite->size, sprite->pos_d_y * sprite->size);
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door_o, sprite->pos_d_x * sprite->size, sprite->pos_d_y * sprite->size);
				}
			}
			return (0);
		}
	}
	else if (str == DIR_RIGHT)
	{
		while (read->line < sprite->pos_y)
			read = read->next;
		if (read->content[sprite->pos_x + 1] != '1')
		{
			if (read->content[sprite->pos_x + 1] == 'C')
			{
				read->content[sprite->pos_x + 1] = '0';
				sprite->flag--;
				if (sprite->flag == 0)
				{
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_d_x * sprite->size, sprite->pos_d_y * sprite->size);
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door_o, sprite->pos_d_x * sprite->size, sprite->pos_d_y * sprite->size);
				}
			}
			return (0);
		}
	}
	return (1);
}
