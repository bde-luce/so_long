/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:34:46 by bde-luce          #+#    #+#             */
/*   Updated: 2024/12/11 17:34:46 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_counter(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.wall,
		2 * SPRITE_SIZE, (data->map.rows - 1) * SPRITE_SIZE);
	mlx_string_put(data->mlx, data->mlx_win, (SPRITE_SIZE * 2),
		(data->map.rows * SPRITE_SIZE) - (SPRITE_SIZE / 2), 0x00000,
		ft_itoa(data->moves));
	data->frame_count = 0;
}

int	player_animation(void *param)
{
	t_data	*data;
	int		animation_speed;

	data = (t_data *)param;
	animation_speed = 20;
	data->frame_count++;
	if ((data->frame_count % animation_speed) % 2 == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.player,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.player2,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
	return (0);
}
