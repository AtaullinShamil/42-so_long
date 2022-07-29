# **************************************************************************** #
#                                                                              #
#    Makefile                                                                  #
#                                                                              #
#    By: Ataullin Shamil                                                       #
#                                                                              #
#    Created: 2022/03/14                                                       #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = so_long.h
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

FILES = main.c map_reading.c check_1.c check_2.c key_hook.c actions.c render.c exit.c enemy.c

OBJ = $(FILES:.c=.o)

all : $(NAME) $(../libft/OBJ)

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIBFT) $(MLX) $(HEADER)
	$(CC) $(FLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

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

