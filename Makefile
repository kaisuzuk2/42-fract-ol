# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:27:30 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/06/21 14:09:28 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
DEBUG = -g -fsanitize=address
FLAG = -Wall -Werror -Wextra -I/usr/include/
MAKE = make -C

FT = libft
FT_LIB = $(FT) + .a
FT_DIR = ./libft

MINILIB = minilibx-linux

SRCS=init.c \
	render.c\
	render_mandelbrot.c \
	key_handler.c \
	event_handler.c \
	mouse_handler.c \
	loop_handler.c
# OBJS=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT)
	$(MAKE) ./$(MINILIB)
	$(CC) $(FLAG) -o $(NAME) $(DEBUG) main.c $(SRCS) -I$(MINILIB) -L$(MINILIB) -lmlx_Linux -lXext -lX11 -lm -L$(FT) -lft

%.o: %.c
	$(CC) $(FLAG) -c -o $@ $<

$(FT):
	$(MAKE) $(FT_DIR)

clean: 
	$(MAKE) ./$(LIMILIB) clean
	
fclean: clean	
	rm -rf $(NAME)

re: fclean all

PYONY: all clean fclean re bonus