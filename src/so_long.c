/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:50:54 by bde-luce          #+#    #+#             */
/*   Updated: 2024/12/10 12:50:54 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	
	t_data	data;

	if (argc == 2)
	{
		map_convert(&data.map, argv);
		map_validity(&data.map, argv);
		map_winnability(data.map);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.map.columns * SPRITE_SIZE,
				data.map.rows * SPRITE_SIZE, "so_long");
		file_to_image(&data);
		initial_map_window(&data);
		data.moves = 0;
		mlx_hook(data.mlx_win, 17, 0, close_window, &data);
		mlx_hook(data.mlx_win, 2, 1L << 0, apply_key, &data);
		mlx_expose_hook(data.mlx_win, initial_map_window, &data);
		mlx_loop_hook(data.mlx, player_animation, &data);
		mlx_loop(data.mlx);
	}
	error_exit("Wrong amount of arguments (!= 2)");
}
