/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:15:22 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/14 14:15:51 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_line(char *path)
{
	int		fd;
	int		line;
	char	buffer;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(write(2, "Invalid fd!\n", 12));
	line = 0;
	while (read(fd, &buffer, 1))
		if (buffer == '\n')
			line++;
	close(fd);
	return (line);
}

t_map	get_map(char *path)
{
	int		i;
	int		fd;
	t_map	map;

	map.map_h = get_line(path);
	map.mat = malloc((map.map_h + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (!map.mat || fd < 0 || map.map_h < 2)
	{
		free_matrix(map.mat);
		ft_putstr_fd("Error ao criar mapa!\n", 1);
		if (fd != -1)
			close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map.map_h)
	{
		map.mat[i] = get_next_line(fd);
		i++;
	}
	map.mat[i] = NULL;
	map.map_w = ft_strlen(map.mat[0]) - 1;
	close(fd);
	return (map);
}

void	free_map(t_map *map)
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

	if (ft_strncmp(path + ft_strlen(path) - 4, ".ber", 4))
	{
		ft_putstr_fd("ERROR! RESOLVE!\n", 2);
		exit(EXIT_FAILURE);
	}
	map = get_map(path);
	if (check_geral(map) == 1)
	{
		ft_putstr_fd("INVALID MAP! RESOLVE!\n", 2);
		free_map(&map);
		exit(EXIT_FAILURE);
	}
	return (map);
}
