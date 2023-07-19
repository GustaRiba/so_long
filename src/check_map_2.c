/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:31:56 by gmorais-          #+#    #+#             */
/*   Updated: 2023/07/18 17:14:45 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_quanti(int player, int e, int collet)
{
	if (player > 1)
	{
		ft_putstr_fd("Muitos players!", 2);
		return (1);
	}
	else if (e > 1)
	{
		ft_putstr_fd("muitas saidas", 2);
		return (1);
	}
	else if (collet == 0)
	{
		ft_putstr_fd("no collet", 2);
		return (1);
	}
	return (0);
}

int	check_elements(t_map map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map.map_h)
	{
		j = 0;
		while (j < map.map_w - 1)
		{
			if (map.mat[i][j] == c)
				count++;
			if (map.mat[i][j] != '1' && map.mat[i][j] != '0' && \
				map.mat[i][j] != 'E' && map.mat[i][j] != 'C' && \
				map.mat[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (count);
}
