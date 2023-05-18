/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:11:28 by gmorais-          #+#    #+#             */
/*   Updated: 2023/05/18 18:00:54 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_map
{
	int		map_h;
	int		map_w;
	char	**mat;
}			t_map;

//map
int	check_geral(t_map map);
