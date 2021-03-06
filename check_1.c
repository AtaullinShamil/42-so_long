/* ************************************************************************** */
/*                                                                            */
/*   check_1.c                                                                */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 022/04/02                                                       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_format(char	*map_format, char	*needed_format)
{
	int	i;
	int	j;

	i = ft_strlen(map_format) - ft_strlen(needed_format);
	j = 0;
	while (map_format[i])
	{
		if (map_format[i] != needed_format[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	ft_check_map_all(char **map)
{
	if (!map[0])
		return (1);
	if (ft_check_map_symbols(map) || ft_check_map_strings(map) \
	|| ft_check_map_walls(map) || ft_check_map_characters(map, 'C') \
	|| ft_check_map_characters(map, 'E') || ft_check_map_start_position(map))
		return (1);
	return (0);
}

void	ft_check_open(t_game *game)
{
	if (ft_get_coins(game))
	{
		game->flag_open = 1;
		game->exit.img = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/exit_open.xpm", &game->exit.height, &game->exit.width);
	}
}
