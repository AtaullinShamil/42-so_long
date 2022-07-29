/* ************************************************************************** */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/03/14                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_game(t_game *game)
{
	ft_get_size(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, \
	"so_long - ntojamur");
	ft_declaration(game);
	ft_map_render(game);
	mlx_hook(game->win, 17, 0, ft_exit, NULL);
	mlx_key_hook(game->win, ft_play, game);
	mlx_loop_hook(game->mlx, ft_enemy, game);
	mlx_loop(game->mlx);
}

static void	ft_parser(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		ft_error(NULL);
	if (!ft_check_map_format(argv[argc - 1], ".ber"))
		ft_error(NULL);
	game->map = ft_get_map(argv[argc - 1]);
	if (!ft_check_map_all(game->map))
		ft_error(NULL);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_parser(&game, argc, argv);
	ft_game(&game);
	return (0);
}
