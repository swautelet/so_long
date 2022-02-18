# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 19:32:53 by swautele          #+#    #+#              #
#    Updated: 2022/02/18 21:52:20 by simonwautel      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I /usr/local/include
LFLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
FILES = src/so_long.c \
		src/draw.c \
		src/error.c \
		src/map_reader.c \
		src/get_next_line.c \
		src/get_next_line_utils.c 
LIBFT = libft/libft.a
OBJECT = $(FILES:.c=.o)
MAP = ./map/map_test.ber
MAPS = ./map

all : $(NAME)

$(NAME) : lib $(OBJECT)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJECT) $(LIBFT) $(LFLAGS) -o $(NAME)

lib :
	make -C libft

test : re
	./$(NAME) $(MAP)

%.o : %.c
	gcc -c $(CFLAGS) $? -o $(?:.c=.o)

clean :
	rm -f $(OBJECT)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

save : fclean
	git add $(FILES) $(MAPS) libft/* Makefile
	git commit -m autosave
	git push https://github.com/swautelet/so_long.git

.phony : $(NAME) clean re test all lib
