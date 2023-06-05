/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:36:02 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/02 13:12:25 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(void)
{
	mlx_destroy_image((*all()).mlx, (*all()).wall);
	mlx_destroy_image((*all()).mlx, (*all()).player);
	mlx_destroy_image((*all()).mlx, (*all()).floor);
	mlx_destroy_image((*all()).mlx, (*all()).cl);
	mlx_destroy_image((*all()).mlx, (*all()).exit_f);
	free_map(&(*all()).map);
	mlx_destroy_window((*all()).mlx, (*all()).win);
	mlx_destroy_display((*all()).mlx);
	free((*all()).mlx);
	exit(EXIT_SUCCESS);
}

void	exit_game(char *str)
{
	if (check_elements((*all()).map, 'X'))
		mlx_destroy_image((*all()).mlx, (*all()).en);
	mlx_destroy_image((*all()).mlx, (*all()).wall);
	mlx_destroy_image((*all()).mlx, (*all()).floor);
	mlx_destroy_image((*all()).mlx, (*all()).cl);
	mlx_destroy_image((*all()).mlx, (*all()).exit_f);
	free_map(&((*all()).map));
	mlx_destroy_window((*all()).mlx, (*all()).win);
	mlx_destroy_display((*all()).mlx);
	free((*all()).mlx);
	ft_putstr_fd(str, 1);
	exit(EXIT_SUCCESS);
}
