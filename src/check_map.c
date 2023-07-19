/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:36:00 by gmorais-          #+#    #+#             */
/*   Updated: 2023/07/18 17:05:40 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_side(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_h)
	{
		if (map.mat[i][0] != '1' || map.mat[i][map.map_w - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_top_bot(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_w - 1)
	{
		if (map.mat[0][i] != '1' || map.mat[map.map_h - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_other(t_map map, int y, int x, int player)
{
	static int	exite;
	static int	collet;

	while (map.mat[y])
	{
		x = 0;
		while (map.mat[y][x])
		{
			if (map.mat[y][x] == 'P')
				player++;
			else if (map.mat[y][x] == 'E')
				exite++;
			else if (map.mat[y][x] == 'C')
				collet++;
			else if (map.mat[y][x] != '1' && map.mat[y][x] \
					!= '0' && map.mat[y][x] != '\n')
				return (1);
			x++;
		}
		y++;
	}
	if (check_quanti(player, exite, collet) == 1)
		return (1);
	return (0);
}

static int	check_formato(t_map map)
{
	if (map.map_h == map.map_w)
		return (1);
	return (0);
}

int	check_geral(t_map map)
{
	if (check_formato(map) == 1)
	{
		ft_putstr_fd("The map is not rectangle!\n", 2);
		return (1);
	}
	if (check_top_bot(map) == 1 || check_side(map) == 1)
	{
		ft_putstr_fd("The map is not closed!\n", 2);
		return (1);
	}
	if (check_other(map, 0, 0, 0) == 1)
	{
		ft_putstr_fd("Ta fdd!\n", 2);
		return (1);
	}
	return (0);
}
