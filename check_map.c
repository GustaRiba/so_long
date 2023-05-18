/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:36:00 by gmorais-          #+#    #+#             */
/*   Updated: 2023/05/18 18:01:50 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_side(t_map map)
{
	int	i;

	while (i < map.map_h)
	{
		if (map.mat[i][0] != '1' || map.mat[i][map.map_w - 1] != '1')
			return (0);
		i++;
	}
}

static int	check_top_bot(t_map map)
{
	int	i;

	while (i < map.map_w - 1)
	{
		if (map.mat[0][i] != '1' || map.mat[map.map_h - 1][i] != '1')
			return (0);
		i++;
	}
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
				map.mat[i][j] != 'X' && map.mat[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (count);
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
		ft_printf("ERROR! Nao sabes oque e um retangulo?\n");
		return (1);
	}
	if (check_top_bot(map) == 1)
	{
		ft_printf ("ERROR! Fecha a puta do mapa!\n");
		return (1);
	}
	if (check_elements(map, 'C') == 1)
	{
		ft_printf("ERROR! Vais coletar oque?\n");
		return (1);
	}
	else if (check_elements(map, 'P') == 1|| check_elements(map, 'E') == 1)
	{
		ft_printf("ERROR! Sem player ou sem saida");
		return (1);
	}
	return (0);
}
