/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:27 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/05 11:50:56 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

void init_img(t_all *img)
{
	int	i;
	
	img->wall = mlx_xpm_file_to_image(img->mlx, "img/wall.xpm", &i, &i);
	img->floor = mlx_xpm_file_to_image(img->mlx, "img/floor.xpm", &i, &i);
	img->cl = mlx_xpm_file_to_image(img->mlx, "img/coin.xpm", &i, &i);
	img->exit_f = mlx_xpm_file_to_image(img->mlx, "img/exit.xpm", &i, &i);
	img->player = mlx_xpm_file_to_image(img->mlx, "img/player.xpm", &i, &i);
	img->nbr_cl = check_elements(img->map, 'C');
	img->nbr_en = check_elements(img->map, 'X');
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit(write(2, "Error\n", 6));
	(*all()).map = create_map(av[1]);
	(*all()).mlx = mlx_init();
	if (!fill_flood())
		return (0);
	init_img(all());
	(*all()).win = mlx_new_window((*all()).mlx, (*all()).map.map_w * 64,
			(*all()).map.map_h * 64, "so_long");
	mlx_hook((*all()).win, 17, 1, ft_close, NULL);
	mlx_hook((*all()).win, 2, 1L << 0, handle_keys, NULL);
	put_img((*all()).map.mat, (*all()));
	mlx_loop((*all()).mlx);
	return (0);
}
