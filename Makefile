# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 16:39:55 by ntojamur          #+#    #+#              #
#    Updated: 2022/04/04 15:45:19 by ntojamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FILES = main.c map_read.c check_1.c check_2.c key_hook.c actions.c render.c exit.c enemy.c

HEADER = so_long.h
LIBFT = libft/libft.a
MLX = mlx/libmlx.a

FLAGS = gcc -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

OBJ = $(FILES:.c=.o)

all : $(NAME) $(../libft/OBJ)

%.o: %.c $(HEADER) Makefile
	$(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIBFT) $(MLX) $(HEADER)
	$(FLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT): easy
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C mlx

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) clean -C libft
	$(MAKE) clean -C mlx

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)
	/bin/rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re bonus easy

