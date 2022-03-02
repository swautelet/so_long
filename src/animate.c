#include "so_long.h"

int	animate(t_img *sprite)
{
	if (sprite->dir == DIR_RIGHT)
	{
		usleep(ANIM_WAIT);
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
		sprite->dir = PAUSE;
	}
	else if (sprite->dir == DIR_DOWN)
	{
		usleep(ANIM_WAIT);
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->floor, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		if (sprite->pos_x == sprite->pos_d_x && sprite->pos_y == sprite->pos_d_y)
			mlx_put_image_to_window(sprite->video, sprite->win, sprite->door, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->pos_y++;
		mlx_put_image_to_window(sprite->video, sprite->win, sprite->player_f2, sprite->pos_x * sprite->size, sprite->pos_y * sprite->size);
		sprite->dir = DIR_DOWN2;
	}
	else if (sprite->dir == DIR_DOWN2)
	{
		usleep(ANIM_WAIT);
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
		sprite->dir = PAUSE;
	}
	else if (sprite->dir == DIR_LEFT)
	{
		usleep(ANIM_WAIT);
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
		sprite->dir = PAUSE;
	}
	return (0);
}