/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:11:28 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/05 13:58:50 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <stdlib.h>

//get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//player merdas
typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

//mapa merdas
typedef struct s_map
{
	int		map_h;
	int		map_w;
	char	**mat;
}			t_map;

//mlx merdas
typedef struct s_all
{
	t_map		map;
	void		*mlx;
	void		*win;
	void		*wall;
	void		*floor;
	void		*c_cd;
	void		*c_ce;
	void		*c_bd;
	void		*c_be;
	void		*b_d;
	void		*b_e;
	void		*b_c;
	void		*b_b;
	void		*player;
	void		*cl;
	void		*en;
	void		*exit_f;
	int			nbr_en;
	int			nbr_cl;
	int			steps;

}			t_all;

//main
t_all		*all(void);

//map
int			check_geral(t_map map);
t_map		create_map(char *path);
int			check_elements(t_map map, char c);
void		free_map(t_map *map);

//keys
int			handle_keys(int o);

//close_game
int			ft_close(void);
void		exit_game(char *str);

//path
int			fill_flood(void);

//img
void		put_img(char **map, t_all img);

//player
t_player	find_player(char **map);
void		move_player(char **map, int x, int y);

//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin_sec(char *str1, char *str2);
int		stashfree(char *buff);

#endif