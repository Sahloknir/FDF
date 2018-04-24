# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axbal <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 14:54:13 by axbal             #+#    #+#              #
#    Updated: 2018/04/24 13:24:46 by axbal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCDIR = sources
SRCS = options.c		\
	   options2.c		\
	   draw_line.c		\
	   read_file.c		\
	   split_to_int.c	\
	   pixel_to_image.c	\
	   gen_colors.c		\
	   utilities.c		\
	   utilities2.c		\
	   gen_map.c		\
	   init.c			\
	   main.c			\

OBJDIR = obj
OBJS = $(SRCS:.c=.o)

SRC = $(addprefix $(SRCDIR)/,$(SRCS))
OBJ = $(addprefix $(OBJDIR)/,$(OBJS))

FLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGl -framework AppKit

LIBFT = ./Libft/libft.a
MLX = ./mlx/libmlx.a

INCLUDE = -Iincludes

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(FRAMEWORK)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	cc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	make -C libft clean
	@rm -rf $(OBJDIR) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
	make -C mlx clean

re: fclean all
