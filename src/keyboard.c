#include "so_long.h"

int	keyplan(int keycode, t_img *sprite)
{
	if (keycode == 53)
		ft_exit(sprite->map);
	if (keycode == 13 && sprite->pos_y > 1)
		move_up(sprite);
	if (keycode == 0 && sprite->pos_x > 0)
		move_left(sprite);
	if (keycode == 1)
		move_down(sprite);
	if (keycode == 2)
		move_right(sprite);
	return(0);
}

int	ft_exit(t_list_c *map)
{
	ft_lstclear_c(&map, free);
	exit(0);
}

void	move_up(t_img *sprite)
{
	if (ft_authorized(sprite, DIR_UP) == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_y--;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
	}
}

void	move_left(t_img *sprite)
{
	if (ft_authorized(sprite, DIR_LEFT) == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_x--;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
	}
}

void	move_down(t_img *sprite)
{
	if (ft_authorized(sprite, DIR_DOWN) == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_y++;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
	}
}

void	move_right(t_img *sprite)
{
	if (ft_authorized(sprite, DIR_RIGHT) == 0)
	{
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_x++;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
	}
}
