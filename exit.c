/* ************************************************************************** */
/*                                                                            */
/*   exit.c                                                                   */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/04/03                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	exit(1);
}

void	ft_error(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_error_map(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_exit(char *str)
{
	if (!str)
		exit(1);
	return (1);
}
