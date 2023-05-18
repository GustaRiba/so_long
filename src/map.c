/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:15:22 by gmorais-          #+#    #+#             */
/*   Updated: 2023/05/18 18:05:38 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->mat[i])
		free(map->mat[i++]);
	free(map->mat);
}

t_map	create_map(char *path)
{
	t_map	map;

	if (ft_strncmp(path + strlen(path) - 4, ".ber", 4))
	{
		ft_printf("ERROR! RESOLVE!\n");
		exit(EXIT_FAILURE);
	}
	map = 
	else if (check_geral(path) == 1)
	{
		ft_printf("INVALID MAP! RESOLVE!");
		free_map(path);
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("VALID MAP\n");
}
