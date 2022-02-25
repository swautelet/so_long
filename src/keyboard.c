#include "so_long.h"

int	keyplan(int keycode, t_list_c *map, t_img *sprite)
{
	(void) map;
	(void)sprite;

	if (keycode == 53)
	{
/*		ft_lstclear_c(&map, free);
		mlx_destroy_window(sprite->video, sprite->win);
		exit(0);*/
		ft_exit(map);
	}
	printf("%d\n", keycode);
	return(0);
}

int	ft_exit(t_list_c *map)
{
	ft_lstclear_c(&map, free);
	exit(0);
}
