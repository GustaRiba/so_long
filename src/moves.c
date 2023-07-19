/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:37:40 by gmorais-          #+#    #+#             */
/*   Updated: 2023/07/19 14:45:33 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player	find_player(char **map)
{
	t_player	coords;
	int flag;

	flag = 0;
	coords.y = 0;
	while (map[coords.y])
	{
		coords.x = 0;
		while (map[coords.y][coords.x])
		{
			if (map[coords.y][coords.x] == 'P')
			{
				flag = 1;
				return (coords);
			}
			coords.x++;
		}
		coords.y++;
	}
	if (flag != 1)
	{
		close_path();
		ft_putstr_fd("ta a dar erro no player wi",2);
		exit(EXIT_FAILURE);
	}
	return (coords);
}

int	check_coli(char **map, int x, int y, char c)
{
	t_player	p;

	p = find_player(map);
	if (map[p.y + y][p.x + x] == c)
		return (1);
	return (0);
}

void	move_player(char **map, int x, int y)
{
	t_player	p;

	p = find_player(map);
	if (check_coli(map, x, y, 'E') && (*all()).nbr_cl == 0)
		exit_game("FIM\n");
	if (!check_coli(map, x, y, '1'))
	{
		if (check_coli(map, x, y, 'C'))
			(*all()).nbr_cl--;
		if (!check_coli(map, x, y, 'E'))
		{
			map[p.y][p.x] = '0';
			map[p.y + y][p.x + x] = 'P';
			(*all()).steps++;
		}
	}
}
