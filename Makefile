# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axbal <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 14:54:13 by axbal             #+#    #+#              #
#    Updated: 2018/02/21 18:59:08 by axbal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = sources/draw_line.c	\
	   sources/read_file.c	\
	   sources/gen_map.c	\
	   sources/gen_colors.c	\
	   main.c				\

SRCO = draw_line.o			\
	   read_file.o			\
	   gen_map.o			\
	   gen_colors.o			\
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
