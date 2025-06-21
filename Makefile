# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:27:30 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/06/21 17:20:38 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
DEBUG = -g -fsanitize=address
FLAG = -Wall -Werror -Wextra -I/usr/include/
MAKE = make -C

FT_DIR = ./libft
FT_LIB = libft.a
FT_INC = -I$(FT_DIR)

MINILIB = minilibx-linux
MINILIB_INC = -I$(MINILIB)
MINILIB_LIB = -L$(MINILIB) -lmlx_Linux -lXext -lX11 -lm

SRCS=init.c \
	render.c\
	mandelbrot.c \
	julia.c \
	key_handler.c \
	event_handler.c \
	mouse_handler.c \
	loop_handler.c

OBJS=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE) $(FT_DIR)
	$(MAKE) $(MINILIB)
	$(CC) $(FLAG) -o $(NAME) $(DEBUG) main.c $(OBJS) $(FT_INC)  $(MINILIB_INC) -L$(FT_DIR) -lft $(MINILIB_LIB)

%.o: %.c
	$(CC) $(FLAG) $(MINILIB_INC) -c $< -o $@

clean:
	$(MAKE) $(FT_DIR) clean
	$(MAKE) $(MINILIB) clean
	rm -rf $(OBJS)
		
fclean: clean	
	rm -rf $(NAME)
	$(MAKE) $(FT_DIR) fclean

re: fclean all

PYONY: all clean fclean re bonus