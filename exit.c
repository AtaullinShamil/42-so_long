/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:28:37 by shamil            #+#    #+#             */
/*   Updated: 2022/04/04 14:42:18 by ntojamur         ###   ########.fr       */
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
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

int	ft_exit(char *str)
{
	if (!str)
		exit(1);
	return (1);
}
