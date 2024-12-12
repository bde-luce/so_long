/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_close_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:42:20 by bde-luce          #+#    #+#             */
/*   Updated: 2024/12/06 17:42:20 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_game(t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->texture.floor)
		mlx_destroy_image(data->mlx, data->texture.floor);
	if (data->texture.wall)
		mlx_destroy_image(data->mlx, data->texture.wall);
	if (data->texture.player)
		mlx_destroy_image(data->mlx, data->texture.player);
	if (data->texture.exit)
		mlx_destroy_image(data->mlx, data->texture.exit);
	if (data->texture.coll)
		mlx_destroy_image(data->mlx, data->texture.coll);
	free_arr(data->map.map);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_game(data);
	exit(0);
}

void	file_to_image(t_data *data)
{
	int	h;
	int	w;

	data->texture.floor = mlx_xpm_file_to_image(data->mlx,
			"textures/floor.xpm", &h, &w);
	data->texture.wall = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &h, &w);
	data->texture.player = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &h, &w);
	data->texture.player2 = mlx_xpm_file_to_image(data->mlx,
			"textures/player2.xpm", &h, &w);	
	data->texture.exit = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &h, &w);
	data->texture.coll = mlx_xpm_file_to_image(data->mlx,
			"textures/coll.xpm", &h, &w);
	if (!data->texture.floor || !data->texture.wall || !data->texture.player
		|| !data->texture.exit || !data->texture.coll)
	{
		write(1, "Error\nTexture(s) not found\n", 27);
		free_game(data);
		exit(0);
	}
}

static void	image_to_window(int i, int j, t_data data)
{
	if (data.map.map[i][j] == '0')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.texture.floor,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (data.map.map[i][j] == '1')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.texture.wall,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (data.map.map[i][j] == 'P')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.texture.player,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (data.map.map[i][j] == 'E')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.texture.exit,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (data.map.map[i][j] == 'C')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.texture.coll,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
}

int	initial_map_window(void *param)
{
	t_data	data;
	int		i;
	int		j;

	data = *(t_data *)param;
	i = 0;
	while (i < data.map.rows)
	{
		j = 0;
		while (j < data.map.columns)
		{
			image_to_window(i, j, data);
			j++;
		}
		i++;
	}
	mlx_string_put(data.mlx, data.mlx_win, (SPRITE_SIZE / 2), (data.map.rows * SPRITE_SIZE) - (SPRITE_SIZE / 2), 0x00000, "MOVES:");
	mlx_string_put(data.mlx, data.mlx_win, (SPRITE_SIZE * 2), (data.map.rows * SPRITE_SIZE) - (SPRITE_SIZE / 2), 0x00000, ft_itoa(data.moves));
	return (0);
}
