/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:30:08 by swautele          #+#    #+#             */
/*   Updated: 2022/03/03 16:22:42 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_authorized(t_img *sprite, char str)
{
	t_list	*read;

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
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_d_x * sprite->siz, sprite->pos_d_y * sprite->siz);
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door_o, sprite->pos_d_x * sprite->siz, sprite->pos_d_y * sprite->siz);
				}
				return (2);
			}
			if (read->content[sprite->pos_x] == 'N')
			{
				printf("You lost. Opal killed you.\n");
				ft_exit(sprite);
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
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_d_x * sprite->siz, sprite->pos_d_y * sprite->siz);
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door_o, sprite->pos_d_x * sprite->siz, sprite->pos_d_y * sprite->siz);
				}
				return (2);
			}
			if (read->content[sprite->pos_x - 1] == 'N')
			{
				printf("You lost. Opal killed you.\n");
				ft_exit(sprite);
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
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_d_x * sprite->siz, sprite->pos_d_y * sprite->siz);
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door_o, sprite->pos_d_x * sprite->siz, sprite->pos_d_y * sprite->siz);
				}
				return (2);
			}
			if (read->content[sprite->pos_x] == 'N')
			{
				printf("You lost. Opal killed you.\n");
				ft_exit(sprite);
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
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_d_x * sprite->siz, sprite->pos_d_y * sprite->siz);
					mlx_put_image_to_window(sprite->video, sprite->win, sprite->door_o, sprite->pos_d_x * sprite->siz, sprite->pos_d_y * sprite->siz);
				}
				return (2);
			}
			if (read->content[sprite->pos_x + 1] == 'N')
			{
				printf("You lost. Opal killed you.\n");
				ft_exit(sprite);
			}
			return (0);
		}
	}
	return (1);
}

void	printmove(t_img *sprite)
{
	mlx_put_image_to_window(sprite->video, sprite->win, sprite->wall, 0 * 64, 0 * 64);
	mlx_string_put(sprite->video, sprite->win, 10, 30, 0x000000, ft_itoa(sprite->move));
}
