/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_winnability.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:42:34 by bde-luce          #+#    #+#             */
/*   Updated: 2024/12/02 11:42:34 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**deep_copy_map(t_map map)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (map.rows + 1));
	if (!copy)
		error_exit("Problem creating deepcopy of map");
	i = 0;
	while (i < map.rows)
	{
		copy[i] = malloc(sizeof(char) * (map.columns + 1));
		if (!copy[i])
		{
			free_arr(copy);
			error_exit("Problem creating deepcopy of map");
		}
		ft_strlcpy(copy[i], map.map[i], map.columns + 1);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	flood_map_c(int i, int j, int *nbr_coll, char **temp)
{
	if (temp[i][j] == 'C')
		(*nbr_coll)--;
	temp[i][j] = '1';
	if (*nbr_coll == 0)
		return (1);
	if (temp[i - 1][j] != '1' && temp[i - 1][j] != 'E'
		&& flood_map_c(i - 1, j, nbr_coll, temp))
		return (1);
	else if (temp[i][j - 1] != '1' && temp[i][j - 1] != 'E'
		&& flood_map_c(i, j - 1, nbr_coll, temp))
		return (1);
	else if (temp[i + 1][j] != '1' && temp[i + 1][j] != 'E'
		&& flood_map_c(i + 1, j, nbr_coll, temp))
		return (1);
	else if (temp[i][j + 1] != '1' && temp[i][j + 1] != 'E'
		&& flood_map_c(i, j + 1, nbr_coll, temp))
		return (1);
	return (0);
}

static int	flood_map_e(int i, int j, char **temp)
{
	if (temp[i][j] == 'E')
		return (1);
	temp[i][j] = '1';
	if (temp[i - 1][j] != '1' && flood_map_e(i - 1, j, temp))
		return (1);
	else if (temp[i][j - 1] != '1' && flood_map_e(i, j - 1, temp))
		return (1);
	else if (temp[i + 1][j] != '1' && flood_map_e(i + 1, j, temp))
		return (1);
	else if (temp[i][j + 1] != '1' && flood_map_e(i, j + 1, temp))
		return (1);
	return (0);
}

void	map_winnability(t_map map)
{
	int		i;
	int		j;
	int		nbr_coll;
	char	**temp;

	i = map.y_player;
	j = map.x_player;
	nbr_coll = map.nbr_coll;
	temp = deep_copy_map(map);
	if (flood_map_c(i, j, &nbr_coll, temp))
	{
		free_arr(temp);
		i = map.y_player;
		j = map.x_player;
		temp = deep_copy_map(map);
		if (flood_map_e(i, j, temp))
		{
			free_arr(temp);
			return ;
		}
	}
	free_arr(temp);
	free_arr(map.map);
	error_exit("Map is not winnable");
}
