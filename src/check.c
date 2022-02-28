#include "so_long.h"

int	ft_authorized(t_img *sprite, char str)
{
	t_list_c	*read;

	read = sprite ->map;
	if (str == '0')
	{
		while (read->line < sprite->pos_y)
			read = read->next;
	}
	return (0);
}