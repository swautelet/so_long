/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:04:20 by swautele          #+#    #+#             */
/*   Updated: 2022/03/08 12:01:09 by swautele         ###   ########.fr       */
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
# define ANIM_WAIT 250000

enum e_dir
{
	DIR_UP = '0',
	DIR_UP2,
	DIR_DOWN,
	DIR_DOWN2,
	DIR_LEFT,
	DIR_RIGHT,
	PAUSE,
};
typedef struct s_reader{
	int			fd;
	char		*line;
	t_list		*map;
	t_list		*new;
	int			i;
}	t_reader;
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
	void		*pl_b;
	void		*pl_b1;
	void		*pl_b2;
	void		*pl_f2;
	void		*pl_f1;
	void		*pl_l;
	void		*pl_l1;
	void		*pl_p_b;
	void		*pl_p_f;
	void		*pl_p_l;
	void		*pl_p_r;
	void		*pl_r;
	void		*pl_r1;
	void		*opal;
	int			s;
	int			flag;
	int			pos_x;
	int			pos_y;
	int			pos_d_x;
	int			pos_d_y;
	int			move;
	char		dir;
	t_list		*map;
	char		done;
}	t_img;
typedef struct s_check{
	size_t	len;
	size_t	height;
	int		i;
	int		player;
	int		exit;
	int		collectible;
}	t_check;
int			ft_error(int argc, char **argv);
t_list		*map_reader(char *name);
char		**map_translate(int const len, int const height, char *name);
char		*get_next_line(int fd);
char		*ft_straddback(char *result, char *buffer, ssize_t size);
size_t		ft_strlengnl(char *str);
int			ft_end_of_line(char *str);
char		*ft_initialize(char *buffer);
char		*gnl(char *result, char *buffer, int size, int fd);
void		ft_straddback2(char *newresult, char *buffer, \
	ssize_t i, ssize_t size);
int			map_error(t_list *map);
int			draw(t_list *map, t_img *sprite);
int			init_sprite(t_list *map);
int			keyplan(int keycode, t_img *sprite);
int			ft_exit(t_img *sprite);
void		move_up(t_img *sprite);
void		move_left(t_img *sprite);
void		move_down(t_img *sprite);
void		move_right(t_img *sprite);
int			ft_authorized(t_img *sprite, int x_off, int y_off);
int			timer(t_img *sprite);
int			animate(t_img *sprite);
void		printmove(t_img *sprite);
int			error_msg(char *str);

#endif
