# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swautele <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 19:32:53 by swautele          #+#    #+#              #
#    Updated: 2022/02/18 18:47:06 by swautele         ###   ########.fr        #
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
		src/libft/libft.a \
		src/get_next_line.c \
		src/get_next_line_utils.c
OBJECT = $(FILES:.c=.o)
MAP = ./map/map_test.ber

all : $(NAME)

$(NAME) : lib $(OBJECT)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJECT) $(LFLAGS) -o $(NAME)

lib :
	make -C libft

test : re
	./$(NAME) $(MAP)

%.o : %.c
	gcc -c $(CFLAGS) $?

clean :
	rm -f $(OBJECT)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

.phony : $(NAME) clean re test all lib
