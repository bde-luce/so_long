/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:47:34 by bde-luce          #+#    #+#             */
/*   Updated: 2024/12/02 11:47:34 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(1);
}

static void	check_file_type(char *file_name)
{
	char *str;
	
	str = ft_substr(file_name, ft_strlen(file_name) - 4, 4);
	if (ft_strncmp(str, ".ber", 4) == 0)
	{
		free(str);
		return ;
	}
	free(str);
	error_exit("Wrong type of file (!= .ber)");
}

int	nbr_rows(char *file_name)
{
	int		fd;
	char	*line;
	int		nbr_rows;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_exit("Error opening map (file)");
	line = get_next_line(fd);
	nbr_rows = 0;
	while (line)
	{
		nbr_rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nbr_rows);
}

void	map_convert(t_map *map, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	check_file_type(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error opening map (file)");
	map->rows = nbr_rows(argv[1]);
	map->map = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->map)
		error_exit("Problem in memory allocation");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->map[i++] = ft_strtrim(line, "\r\n");
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->map[i] = NULL;
	close(fd);
}
