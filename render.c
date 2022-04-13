/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:42:32 by shamil            #+#    #+#             */
/*   Updated: 2022/04/04 15:18:42 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_render_helper(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->wall.img, x * 32, y * 32);
	if (c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'B')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->floor.img, x * 32, y * 32);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->exit.img, x * 32, y * 32);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->player.img, x * 32, y * 32);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->coin.img, x * 32, y * 32);
	if (c == 'B')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->enemy.img, x * 32, y * 32);
}

void	ft_map_render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] && !game->flag_win && !game->flag_lose)
	{
		x = 0;
		while (game->map[y][x])
		{
			map_render_helper(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw_win(t_game *game)
{
	char	*steps;

	ft_putnbr_fd(game->steps, 1);
	ft_putchar_fd('\n', 1);
	mlx_clear_window(game->mlx, game->win);
	steps = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, \
	(game->width - 16) / 2, game->height / 2 - 16, 0x0066FF33, "you win!");
	mlx_string_put(game->mlx, game->win, \
	(game->width - 16) / 2, game->height / 2 + 16, 0x0066FF33, steps);
	mlx_string_put(game->mlx, game->win, \
	(game->width - 16) / 2, game->height / 2 + 32, 0x0066FF33, "steps");
	free(steps);
}

void	ft_print_steps(t_game *game)
{
	ft_putnbr_fd(game->steps, 1);
	ft_putchar_fd('\n', 1);
}
