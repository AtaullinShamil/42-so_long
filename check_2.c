/* ************************************************************************** */
/*                                                                            */
/*   check_2.c                                                                */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 022/04/02                                                       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_symbols(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C' && \
			map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != 'B')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_map_strings(char **map)
{
	int		y;
	size_t	len;

	y = 0;
	len = ft_strlen(map[0]);
	while (map[y])
	{
		if (ft_strlen(map[y]) != len)
			return (1);
		y++;
	}
	if (y < 3)
		return (1);
	return (0);
}

int	ft_check_map_walls(char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[0][++x])
		if (map[0][x] != '1')
			return (1);
	y = -1;
	while (map[++y])
		if (map[y][0] != '1' || map[y][ft_strlen(map[y]) - 1] != '1')
			return (1);
	x = -1;
	while (map[y - 1][++x] != '1')
		if (map[y - 1][x] != '1')
			return (1);
	return (0);
}

int	ft_check_map_characters(char **map, char c)
{
	int	x;
	int	y;
	int	p;

	y = -1;
	p = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == c)
				p++;
	}
	if (p < 1)
		return (1);
	return (0);
}

int	ft_check_map_start_position(char **map)
{
	int	x;
	int	y;
	int	p;

	y = -1;
	p = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'P')
				p++;
	}
	if (p != 1)
		return (1);
	return (0);
}
