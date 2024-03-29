# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swautele <swautele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 19:32:53 by swautele          #+#    #+#              #
#    Updated: 2022/03/09 15:11:55 by swautele         ###   ########.fr        #
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
		src/get_next_line_utils.c \
		src/keyboard.c \
		src/check.c \
		src/animate.c \
		src/dir.c \
		src/init.c
LIBFT = libft/libft.a
OBJECT = $(FILES:.c=.o)
MAP = map/map_test.ber
MAPS = ./map
HEADER = ./src/so_long.h
SPRITE = ./sprite

all : $(NAME)

$(NAME) : $(OBJECT)
	make bonus -C libft
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJECT) $(LIBFT) $(LFLAGS) -o $(NAME)

test : all
	./$(NAME) $(MAP)

%.o : %.c
	gcc -c $(CFLAGS) $? -o $(?:.c=.o)

clean :
	rm -f $(OBJECT)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

save : 
	git commit -am autosave
	git push https://github.com/swautelet/so_long.git

.phony : $(NAME) clean re test all lib fclean
