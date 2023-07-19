/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:36:02 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/14 14:12:16 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

int	ft_close(void)
{
	mlx_clear_window((*all()).mlx, (*all()).win);
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
	mlx_destroy_image((*all()).mlx, (*all()).player);
	mlx_clear_window((*all()).mlx, (*all()).win);
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

void	close_path(void)
{
	free_map(&(*all()).map);
	exit(EXIT_FAILURE);
}
