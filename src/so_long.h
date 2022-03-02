/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:04:20 by swautele          #+#    #+#             */
/*   Updated: 2022/03/02 15:52:00 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <strings.h>
# include <errno.h>
# include <limits.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <time.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define ANIM_WAIT 50000

enum e_dir
{
	DIR_UP = '0',
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

typedef struct s_img{
	void		*poopbag;
	void		*key;
	void		*player;
	void		*leash;
	void		*collar;
	void		*boot;
	void		*video;
	void		*win;
	void		*floor;
	void		*wall;
	void		*loki;
	void		*door;
	void		*door_o;
	void		*player_b;
	void		*player_b1;
	void		*player_b2;
	void		*player_f2;
	void		*player_f1;
	void		*player_l;
	void		*player_l1;
	void		*player_p_b;
	void		*player_p_f;
	void		*player_p_l;
	void		*player_p_r;
	void		*player_r;
	void		*player_r1;
	void		*opal;
	int			size;
	int			flag;
	int			pos_x;
	int			pos_y;
	int			pos_d_x;
	int			pos_d_y;
	int			move;
	char		dir;
	t_list_c	*map;
}	t_img;

int			ft_error(int argc, char **argv);
t_list_c	*map_reader(char *name);
char		**map_translate(int const len, int const height, char *name);
char		*get_next_line(int fd);
char		*ft_straddback(char *result, char *buffer, ssize_t size);
size_t		ft_strlengnl(char *str);
int			ft_end_of_line(char *str);
char		*ft_initialize(char *buffer);
char		*gnl(char *result, char *buffer, int size, int fd);
void		ft_straddback2(char *newresult, char *buffer, ssize_t i, ssize_t size);
int			map_error(t_list_c *map);
int			draw(t_list_c *map, t_img *sprite);
int			init_sprite(t_list_c *map);
int			keyplan(int keycode, t_img *sprite);
int			ft_exit(t_img *sprite);
void		move_up(t_img *sprite);
void		move_left(t_img *sprite);
void		move_down(t_img *sprite);
void		move_right(t_img *sprite);
int			ft_authorized(t_img *sprite, char str);
int			timer(t_img *sprite);

#endif
