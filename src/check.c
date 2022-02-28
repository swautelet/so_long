#include "so_long.h"

int	ft_authorized(t_img *sprite, char str)
{
	t_list_c	*read;

	printf("%d\n", sprite->flag);
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
			}
			return (0);
		}
	}
	return (1);
}