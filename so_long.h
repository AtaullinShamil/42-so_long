/* ************************************************************************** */
/*                                                                            */
/*   so_long.h                                                                */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/03/14                                                      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_img {
	void	*img;
	int		width;
	int		height;

}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	t_img	player;
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	floor;
	t_img	enemy;
	int		flag_win;
	int		flag_lose;
	int		flag_open;
	int		currently_x;
	int		currently_y;
	int		steps;
}	t_game;

int		ft_check_map_format(char *map_format, char *needed_format);
char	**ft_get_map(char *file);
int		ft_check_map_all(char **map);
int		ft_check_map_symbols(char **map);
int		ft_check_map_strings(char **map);
int		ft_check_map_walls(char **map);
int		ft_check_map_characters(char **map, char c);
int		ft_check_map_start_position(char **map);
void	ft_check_open(t_game *game);

void	ft_get_size(t_game *game);
void	ft_declaration(t_game *game);
void	ft_map_render(t_game *game);
int		ft_play(int key, t_game *game);
void	ft_player_position(t_game *game);
void	ft_new_position(t_game *game, int nx, int ny);
int		ft_enemy(t_game *game);
int		ft_get_coins(t_game *game);

void	ft_draw_win(t_game *game);
void	ft_print_steps(t_game *game);

void	ft_error(char *str);
void	ft_error_map(char **res);
void	ft_free(char **res);
int		ft_exit(char *str);

#endif
