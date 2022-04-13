/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:49:08 by shamil            #+#    #+#             */
/*   Updated: 2022/04/04 14:42:20 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_up(t_game	*game)
{
	mlx_clear_window(game->mlx, game->win);
	game->player.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/player_up.xpm", &game->enemy.width, &game->enemy.height);
	ft_player_position(game);
	ft_new_position(game, game->currently_x, game->currently_y - 1);
}

static void	ft_move_left(t_game	*game)
{
	mlx_clear_window(game->mlx, game->win);
	game->player.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/player_left.xpm", &game->enemy.width, &game->enemy.height);
	ft_player_position(game);
	ft_new_position(game, game->currently_x - 1, game->currently_y);
}

static void	ft_move_down(t_game	*game)
{
	mlx_clear_window(game->mlx, game->win);
	game->player.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/player_down.xpm", &game->enemy.width, &game->enemy.height);
	ft_player_position(game);
	ft_new_position(game, game->currently_x, game->currently_y + 1);
}

static void	ft_move_right(t_game	*game)
{
	mlx_clear_window(game->mlx, game->win);
	game->player.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/player_right.xpm", &game->enemy.width, &game->enemy.height);
	ft_player_position(game);
	ft_new_position(game, game->currently_x + 1, game->currently_y);
}

int	ft_play(int key, t_game *game)
{
	if (key == 53)
		ft_free(game->map);
	if (!game->flag_win)
	{
		if (!game->flag_lose && !game->flag_win)
		{
			if (key == 2)
				ft_move_right(game);
			if (key == 0)
				ft_move_left(game);
			if (key == 13)
				ft_move_up(game);
			if (key == 1)
				ft_move_down(game);
		}
		if (game->flag_win)
			ft_draw_win(game);
	}
	return (0);
}
