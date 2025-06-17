# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:27:30 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/06/17 14:21:58 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
CC=cc
FLAG=-Wall -Werror -Wextra
MAKE=make -C
SRCS=init.c
# OBJS=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE) ./minilibx-linux
	# cp ./minilibx-linux/libmlx_Linux.a .
	$(CC) $(FLAG) -o $(NAME) main.c $(SRCS) -Iminilibx-linux -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm

%.o: %.c
	$(CC) $(FLAG) -c -o $@ $<

clean: 
	$(MAKE) ./minilibx-linux clean
	
fclean: clean	
	rm -rf $(NAME)

re: fclean all

PYONY: all clean fclean re bonus