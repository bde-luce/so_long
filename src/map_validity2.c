/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:01:39 by bde-luce          #+#    #+#             */
/*   Updated: 2024/12/02 12:01:39 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_char(char c, t_map *map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == c)
			{
				if (c == 'P')
				{
					map->x_player = j;
					map->y_player = i;
				}
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	special_char_nbr(t_map *map)
{
	int	c;
	int	e;
	int	p;

	c = count_char('C', map);
	map->nbr_coll = c;
	e = count_char('E', map);
	p = count_char('P', map);
	if (c >= 1 && e == 1 && p == 1)
		return (1);
	return (0);
}

int	map_is_closed(t_map map, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < map.columns)
	{
		if (map.map[i][j] != '1')
			return (0);
	}
	i++;
	j--;
	while (i < (nbr_rows(argv[1]) - 1))
	{
		if (map.map[i][0] != '1' || map.map[i][j] != '1')
			return (0);
		i++;
	}
	j = -1;
	while (++j < map.columns)
	{
		if (map.map[i][j] != '1')
			return (0);
	}
	return (1);
}

void	map_validity(t_map *map, char **argv)
{
	if (!is_rectangle(map, argv[1]))
	{
		free_arr(map->map);
		error_exit("Map is not a rectangle");
	}
	if (!char_is_valid(*map))
	{
		free_arr(map->map);
		error_exit("Character(s) is(are) not valid");
	}
	if (!special_char_nbr(map))
	{
		free_arr(map->map);
		error_exit("Wrong amount of special characters (C, E or P)");
	}
	if (!map_is_closed(*map, argv))
	{
		free_arr(map->map);
		error_exit("Map is not closed");
	}
}
