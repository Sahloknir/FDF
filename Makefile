# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axbal <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 14:54:13 by axbal             #+#    #+#              #
#    Updated: 2018/01/30 12:16:15 by axbal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = sources/draw_line.c	\
	   main.c				\

SRCO = draw_line.o			\
	   main.o				\

FLAGS = -Wall -Wextra -Werror

LIBFT = ./Libft/libft.a

MLX = ./mlx/libmlx.a

FRAMEWORK = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCO)
	gcc -o $(NAME) $(LIBFT) $(MLX) $(SRCO) $(FRAMEWORK)

$(SRCO): $(SRCS)
	gcc -c $(FLAGS) $(SRCS)

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	rm -rf $(SRCO)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
	make -C mlx clean

re: fclean all
