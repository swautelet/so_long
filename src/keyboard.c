#include "so_long.h"

int	keyplan(int keycode, t_img *sprite)
{
	if (keycode == 53)
		ft_exit(sprite->map);
	if (keycode == 13)
		move_up(sprite);
	printf("%d\n", keycode);
	return(0);
}

int	ft_exit(t_list_c *map)
{
	ft_lstclear_c(&map, free);
	exit(0);
}

void	move_up(t_img *sprite)
{
	printf("%p", sprite);
}