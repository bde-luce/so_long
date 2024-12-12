/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:12:56 by bde-luce          #+#    #+#             */
/*   Updated: 2024/11/23 19:12:56 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		x_player;
	int		y_player;
	int		nbr_coll;
}	t_map;

typedef struct s_texture
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*player2;
	void	*exit;
	void	*coll;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			moves;
	int			frame_count;
	t_map		map;
	t_texture	texture;
}	t_data;

#define SPRITE_SIZE 32

void	error_exit(char *str);
int		nbr_rows(char *file_name);
void	map_convert(t_map *map, char **argv);

int		is_rectangle(t_map *map, char *file_name);
int		char_is_valid(t_map map);

int		special_char_nbr(t_map *map);
int		map_is_closed(t_map map, char **argv);
void	map_validity(t_map *map, char **argv);

void	free_arr(char **arr);
void	map_winnability(t_map map);

void	file_to_image(t_data *data);
int		initial_map_window(void *param);
int		close_window(void *param);

int		apply_key(int keycode, void *param);

void	print_counter(t_data *data);
int		player_animation(void *param);

#endif