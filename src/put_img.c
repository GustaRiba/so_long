/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:58:33 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/14 14:10:55 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	choose_img(char c, int x, int y, t_all img)
{
	if (c == '1')
		mlx_put_image_to_window(img.mlx, img.win, img.wall, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(img.mlx, img.win, img.floor, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(img.mlx, img.win, img.cl, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(img.mlx, img.win, img.player, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(img.mlx, img.win, img.exit_f, x * 64, y * 64);
}

void	print_step(void)
{
	char	*steps;
	char	*str;

	steps = ft_itoa((*all()).steps);
	str = ft_strjoin("steps = ", steps);
	mlx_string_put((*all()).mlx, (*all()).win, 50, 50, 0xFF0000, str);
	free(str);
	free(steps);
}

void	put_img(char **map, t_all img)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			choose_img(map[i][j], j, i, img);
			j++;
		}
		i++;
	}
	print_step();
}
