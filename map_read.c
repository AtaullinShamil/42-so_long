/* ************************************************************************** */
/*                                                                            */
/*   map_read.c                                                               */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/04/02                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_string_init(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		ft_error(NULL);
	str[0] = '\0';
	return (str);
}

static char	*ft_read(char *file)
{
	char	*map_string;
	char	buffer[1000 + 1];
	char	*str;
	int		fd;
	int		return_value;

	fd = open(file, O_RDONLY);
	return_value = 1;
	map_string = ft_string_init();
	while (return_value)
	{
		return_value = read(fd, buffer, 1000);
		if (return_value < 0)
			ft_error(map_string);
		buffer[return_value] = '\0';
		str = map_string;
		map_string = ft_strjoin(str, buffer);
		free (str);
		if (!map_string)
			ft_error(NULL);
	}
	return (map_string);
}

char	**ft_get_map(char *file)
{
	char	*line;
	char	**map;

	line = ft_read(file);
	map = ft_split(line, '\n');
	if (!map)
		ft_error(line);
	if (line)
		free(line);
	return (map);
}
