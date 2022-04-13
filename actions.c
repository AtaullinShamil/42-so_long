/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:52:23 by shamil            #+#    #+#             */
/*   Updated: 2022/04/04 14:52:07 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_position(t_game *game, int nx, int ny)
{
	if (game->map[ny][nx] == 'E' && game->flag_open)
	{
		game->flag_win = 1;
		game->steps++;
		return ;
	}
	if (game->map[ny][nx] != '1' && game->map[ny][nx] != 'E')
	{
		if (game->map[ny][nx] == 'B')
		{
			game->flag_lose = 1;
			game->steps++;
			ft_print_steps(game);
			return ;
		}
		game->map[game->currently_y][game->currently_x] = '0';
		game->map[ny][nx] = 'P';
		game->steps++;
		ft_check_open(game);
		if (!game->flag_win)
			ft_print_steps(game);
	}
	ft_map_render(game);
}

void	ft_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->currently_x = x;
				game->currently_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_get_size(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y][x])
		x++;
	while (game->map[y])
		y++;
	game->width = x * 32;
	game->height = y * 32;
}

int	ft_get_coins(t_game *game)
{
	int	x;
	int	y;

	if (game->flag_open == 1)
		return (1);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_declaration(t_game *game)
{
	game->flag_open = 0;
	game->flag_lose = 0;
	game->flag_win = 0;
	game->steps = 0;
	game->player.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/player_right.xpm", &game->player.width, &game->player.height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/wall.xpm", &game->wall.width, &game->wall.height);
	game->coin.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/coin.xpm", &game->coin.width, &game->coin.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/floor.xpm", &game->floor.width, &game->floor.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/exit.xpm", &game->exit.width, &game->exit.height);
	game->enemy.img = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/enemy_left.xpm", &game->enemy.width, &game->enemy.height);
}
