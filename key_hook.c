/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:44:34 by bde-luce          #+#    #+#             */
/*   Updated: 2024/12/06 17:44:34 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_left(t_data *data)
{
	if (data->map.map[data->map.y_player][data->map.x_player - 1] == '1')
		return (0);
	else if (data->map.map[data->map.y_player][data->map.x_player - 1] == 'E')
	{
		if (data->map.nbr_coll == 0)
			close_window(data);
		else
			return (0);
	}
	else
	{
		if (data->map.map[data->map.y_player][data->map.x_player - 1] == 'C')
			data->map.nbr_coll--;
		data->map.map[data->map.y_player][data->map.x_player] = '0';
		data->map.map[data->map.y_player][data->map.x_player - 1] = 'P';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.floor,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
		data->map.x_player--;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.player,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
		data->moves++;
		ft_printf("moves: %d\n", data->moves);
	}
	return (0);
}

static int	move_up(t_data *data)
{
	if (data->map.map[data->map.y_player - 1][data->map.x_player] == '1')
		return (0);
	else if (data->map.map[data->map.y_player - 1][data->map.x_player] == 'E')
	{
		if (data->map.nbr_coll == 0)
			close_window(data);
		else
			return (0);
	}
	else
	{
		if (data->map.map[data->map.y_player - 1][data->map.x_player] == 'C')
			data->map.nbr_coll--;
		data->map.map[data->map.y_player][data->map.x_player] = '0';
		data->map.map[data->map.y_player - 1][data->map.x_player] = 'P';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.floor,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
		data->map.y_player--;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.player,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
		data->moves++;
		ft_printf("moves: %d\n", data->moves);
	}
	return (0);
}

static int	move_right(t_data *data)
{
	if (data->map.map[data->map.y_player][data->map.x_player + 1] == '1')
		return (0);
	else if (data->map.map[data->map.y_player][data->map.x_player + 1] == 'E')
	{
		if (data->map.nbr_coll == 0)
			close_window(data);
		else
			return (0);
	}
	else
	{
		if (data->map.map[data->map.y_player][data->map.x_player + 1] == 'C')
			data->map.nbr_coll--;
		data->map.map[data->map.y_player][data->map.x_player] = '0';
		data->map.map[data->map.y_player][data->map.x_player + 1] = 'P';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.floor,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
		data->map.x_player++;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.player,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
		data->moves++;
		ft_printf("moves: %d\n", data->moves);
	}
	return (0);
}

static int	move_down(t_data *data)
{
	if (data->map.map[data->map.y_player + 1][data->map.x_player] == '1')
		return (0);
	else if (data->map.map[data->map.y_player + 1][data->map.x_player] == 'E')
	{
		if (data->map.nbr_coll == 0)
			close_window(data);
		else
			return (0);
	}
	else
	{
		if (data->map.map[data->map.y_player + 1][data->map.x_player] == 'C')
			data->map.nbr_coll--;
		data->map.map[data->map.y_player][data->map.x_player] = '0';
		data->map.map[data->map.y_player + 1][data->map.x_player] = 'P';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.floor,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
		data->map.y_player++;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.player,
			data->map.x_player * SPRITE_SIZE, data->map.y_player * SPRITE_SIZE);
		data->moves++;
		ft_printf("moves: %d\n", data->moves);
	}
	return (0);
}

int	apply_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
		close_window(param);
	if (keycode == 65361)
		move_left(data);
	if (keycode == 65362)
		move_up(data);
	if (keycode == 65363)
		move_right(data);
	if (keycode == 65364)
		move_down(data);
	print_counter(data);
	return (0);
}
