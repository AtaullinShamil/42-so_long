/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 00:21:21 by shamil            #+#    #+#             */
/*   Updated: 2022/04/04 14:42:17 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_enemy_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'B')
			{
				game->currently_x = x;
				game->currently_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	ft_render_enemy(t_game *game, char *sprite, int sign)
{
	if (ft_enemy_position(game))
	{
		game->enemy.img = mlx_xpm_file_to_image(game->mlx, \
		sprite, &game->enemy.width, &game->enemy.height);
		if (game->map[game->currently_y][game->currently_x + sign] != '1' \
		&& game->map[game->currently_y][game->currently_x + sign] != 'E' \
		&& game->map[game->currently_y][game->currently_x + sign] != 'C')
		{
			if (game->map[game->currently_y][game->currently_x + sign] == 'P')
				game->flag_lose = 1;
			else
				game->map[game->currently_y][game->currently_x] = '0';
			game->map[game->currently_y][game->currently_x + sign] = 'B';
		}
	}
	else
		return ;
}

static void	ft_sprite_enemy(t_game *game)
{
	static int	acc = -60;
	char		*steps;

	if (acc == -90)
		ft_render_enemy(game, "./sprites/enemy_left.xpm", -1);
	if (acc == -60)
		ft_render_enemy(game, "./sprites/enemy_right.xpm", 0);
	if (acc == -30)
		ft_render_enemy(game, "./sprites/enemy_right.xpm", 1);
	if (acc == 0)
		ft_render_enemy(game, "./sprites/enemy_right.xpm", 1);
	if (acc == 30)
		ft_render_enemy(game, "./sprites/enemy_left.xpm", 0);
	if (acc == 60)
		ft_render_enemy(game, "./sprites/enemy_left.xpm", -1);
	acc++;
	if (acc > 90)
		acc = -90;
	ft_map_render(game);
	if (!game->flag_win)
	{
		steps = ft_itoa(game->steps);
		mlx_string_put(game->mlx, game->win, 5, 15, 0x0066FF33, steps);
		free(steps);
	}
}

int	ft_enemy(t_game *game)
{
	char	*steps;

	if (!game->flag_lose)
		ft_sprite_enemy(game);
	else
	{
		steps = ft_itoa(game->steps);
		mlx_clear_window(game->mlx, game->win);
		mlx_string_put(game->mlx, game->win, \
		game->width / 2 - 32, game->height / 2 - 32, 0x0066FF33, "you lose");
		mlx_string_put(game->mlx, game->win, 0, 0, 0x0066FF33, steps);
		free(steps);
	}
	return (1);
}

/*static void	ft_render_enemy(t_game *game, char *sprite, int sign)
{
	game->enemy.img = mlx_xpm_file_to_image(game->mlx, \
	sprite, &game->enemy.width, &game->enemy.height);
	if (game->map[game->currently_y][game->currently_x + sign] != '1' \
	&& game->map[game->currently_y][game->currently_x + sign] != 'E' \
	&& game->map[game->currently_y][game->currently_x + sign] != 'C')
	{
		if (game->map[game->currently_y][game->currently_x + sign] == 'P')
			game->flag_lose = 1;
		else
			game->map[game->currently_y][game->currently_x] = '0';
		game->map[game->currently_y][game->currently_x + sign] = 'B';
	}
}

static void	ft_enemy_position(t_game *game, char *sprite, int sign)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'B')
			{
				game->currently_x = x;
				game->currently_y = y;
				ft_render_enemy(game, sprite, sign);
			}
			x++;
		}
		y++;
	}
}

static void	ft_sprite_enemy(t_game *game)
{
	static int	acc = -60;
	char		*steps;

	if (acc == -90)
		ft_enemy_position(game, "./sprites/enemy_left.xpm", -1);
	if (acc == -60)
		ft_enemy_position(game, "./sprites/enemy_right.xpm", 0);
	if (acc == -30)
		ft_enemy_position(game, "./sprites/enemy_right.xpm", 1);
	if (acc == 0)
		ft_enemy_position(game, "./sprites/enemy_right.xpm", 1);
	if (acc == 30)
		ft_enemy_position(game, "./sprites/enemy_left.xpm", 0);
	if (acc == 60)
		ft_enemy_position(game, "./sprites/enemy_left.xpm", -1);
	acc++;
	if (acc > 90)
		acc = -90;
	ft_map_render(game);
	if (!game->flag_win)
	{
		steps = ft_itoa(game->steps);
		mlx_string_put(game->mlx, game->win, 5, 15, 0x0066FF33, steps);
		free(steps);
	}
}

int	ft_enemy(t_game *game)
{
	char	*steps;

	if (!game->flag_lose)
		ft_sprite_enemy(game);
	else
	{
		steps = ft_itoa(game->steps);
		mlx_clear_window(game->mlx, game->win);
		mlx_string_put(game->mlx, game->win, \
		game->width / 2 - 32, game->height / 2 - 32, 0x0066FF33, "you lose");
		mlx_string_put(game->mlx, game->win, 0, 0, 0x0066FF33, steps);
		free(steps);
	}
	return (1);
}*/
