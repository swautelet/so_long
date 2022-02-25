#include "so_long.h"

int	keyplan(int keycode, t_list_c *map, t_img *sprite)
{
	(void) map;

	if (keycode == 53)
		exit(mlx_destroy_window(sprite->video, sprite->win));
	printf("%d\n", keycode);
	return(0);
}
