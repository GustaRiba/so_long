/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:19:21 by gmorais-          #+#    #+#             */
/*   Updated: 2023/07/19 14:43:03 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static int	count_collet(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'C')
				count++;
		y++;
	}
	return (count);
}

static void	find_path_collet(char **tmp, int x, int y)
{
	tmp[y][x] = 'V';
	if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != 'V' && tmp[y][x + 1] != 'E')
		find_path_collet(tmp, x + 1, y);
	if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != 'V' && tmp[y][x - 1] != 'E')
		find_path_collet(tmp, x - 1, y);
	if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != 'V' && tmp[y + 1][x] != 'E')
		find_path_collet(tmp, x, y + 1);
	if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != 'V' && tmp[y - 1][x] != 'E')
		find_path_collet(tmp, x, y - 1);
}

static int	find_path_exit(char **tmp, int x, int y)
{
	static int	exit;

	if (tmp[y][x] == 'E')
		exit++;
	tmp[y][x] = 'V';
	if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != 'V')
		find_path_exit(tmp, x + 1, y);
	if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != 'V')
		find_path_exit(tmp, x - 1, y);
	if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != 'V')
		find_path_exit(tmp, x, y + 1);
	if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != 'V')
		find_path_exit(tmp, x, y - 1);
	return (exit);
}

int	check_path(void)
{
	char		**tmp;
	int			collet;
	int			valid;
	t_player	p;

	tmp = map_copy();
	if (!tmp)
		return (0);
	p = find_player(tmp);
	find_path_collet(tmp, p.x, p.y);
	collet = count_collet(tmp);
	free_matrix(tmp);
	tmp = map_copy();
	valid = (find_path_exit(tmp, p.x, p.y) && !collet);
	free_matrix(tmp);
	if (!valid)
	{
		ft_putstr_fd("provided map does not contain a valid path.", 2);
		return (0);
	}
	return (1);
}
