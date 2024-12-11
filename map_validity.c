/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:08:00 by bde-luce          #+#    #+#             */
/*   Updated: 2024/11/26 20:08:00 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != '\r')
		i++;
	return (i);
}

static void	check_empty_map(int fd, char *line, t_map *map)
{
	if (!line)
	{
		close(fd);
		free_arr(map->map);
		error_exit("Map is empty");
	}
}

int	is_rectangle(t_map *map, char *file_name)
{
	int		fd;
	char	*line;
	int		len_1stline;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_exit("Error opening map (file)");
	line = get_next_line(fd);
	check_empty_map(fd, line, map);
	len_1stline = line_len(line);
	while (line)
	{
		if (len_1stline != line_len(line))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line),
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->columns = len_1stline;
	return (len_1stline);
}

static int	valid_char(char c)
{
	if (c != '0')
	{
		if (c != '1')
		{
			if (c != 'P')
			{
				if (c != 'E')
				{
					if (c != 'C')
						return (1);
				}
			}
		}
	}
	return (0);
}

int	char_is_valid(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.columns)
		{
			if (valid_char(map.map[i][j]) == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
