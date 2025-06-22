# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:27:30 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/06/22 20:21:19 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
DEBUG = -g -fsanitize=address
FLAG = -Wall -Werror -Wextra -I/usr/include/

MAKE = make -C
RM = rm -rf

FT_DIR = ./libftprintf
FT_LIB = libftprintf.a
FT_INC = -I$(FT_DIR)/includes -I./libftprintf/libft

MINILIB = minilibx-linux
MINILIB_INC = -I$(MINILIB)
MINILIB_LIB = -L$(MINILIB) -lmlx_Linux -lXext -lX11 -lm

MAIN = main.c
_SRCS = init.c \
	parse.c \
	render.c \
	buf_mlx_pixel_put.c \
	mandelbrot.c \
	julia.c \
	key_handler.c \
	event_handler.c \
	mouse_handler.c \
	loop_handler.c

SRCS = $(addprefix src/, $(_SRCS))

OBJS=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(MAIN)
	$(MAKE) $(FT_DIR)
	$(MAKE) $(MINILIB)
	$(CC) $(FLAG) -o $(NAME) -Iincludes $(MAIN) $(OBJS) $(FT_INC)  $(MINILIB_INC) -L$(FT_DIR) -lftprintf $(MINILIB_LIB)

%.o: %.c
	$(CC) $(FLAG) -Iincludes $(MINILIB_INC) $(FT_INC) -c $< -o $@

clean:
	$(MAKE) $(FT_DIR) clean
	$(MAKE) $(MINILIB) clean
	$(RM) $(OBJS)
		
fclean: clean	
	$(RM) $(NAME)
	$(MAKE) $(FT_DIR) fclean

re: fclean all

PYONY: all clean fclean re bonus