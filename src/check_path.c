/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:19:21 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/05 13:54:51 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(int x, int y, int *flag, char **tmp)
{
	if (tmp[y][x] == '1' || tmp[y][x] == 'P' || tmp[y][x] == 'D')
		return ;
	else if (tmp[y][x] == '0')
		tmp[y][x] = 'P';
	else if (tmp [y][x] == 'C' || tmp[y][x] == 'X')
		tmp[y][x] = 'D';
	else if (tmp[y][x] == 'E')
	{
		(*flag)++;
		tmp[y][x] = 'E';
	}
	flood_fill(x + 1, y, flag, tmp);
	flood_fill(x - 1, y, flag, tmp);
	flood_fill(x, y + 1, flag, tmp);
	flood_fill(x, y - 1, flag, tmp);
}

static int	check_collec(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

char	**map_copy(void)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = ft_calloc((*all()).map.map_h + 1, sizeof(char *));
	if (!copy)
		return (0);
	while (i < (*all()).map.map_h)
	{
		copy[i] = ft_calloc((*all()).map.map_w +1, sizeof(char *));
		j = 0;
		if (!copy[i])
		{
			free_matrix(copy);
			return (0);
		}
		while (j < (*all()).map.map_w)
		{
			copy[i][j] = (*all()).map.mat[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

int	fill_flood(void)
{
	t_player	p;
	int			flag;
	char		**map;

	flag = 0;
	map = map_copy();
	p = find_player(map);
	flood_fill(p.x + 1, p.y, &flag, map);
	flood_fill(p.x - 1, p.y, &flag, map);
	flood_fill(p.x, p.y + 1, &flag, map);
	flood_fill(p.x, p.y - 1, &flag, map);
	if (flag == 0 || !check_collec(map))
	{
		 ft_putstr_fd("Invalid path\n", 2);
		 free_matrix(map);
		 return (0);
	}
	free_matrix(map);
	return (1);
}
