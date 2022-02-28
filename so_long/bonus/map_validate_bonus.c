/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:21:49 by slammari          #+#    #+#             */
/*   Updated: 2022/02/27 19:41:11 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map(char *file, t_map	*map)
{
	char	*line;
	int		fd;

	map->width = 0;
	map->height = 0;
	check_extension_map(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error read map\n");
		exit(1);
	}
	while (ft_read(fd, &line))
	{
		if (!map->width)
			map->width = ft_strlen_nl(line);
		if (map->width != ft_strlen_nl(line))
		{
			ft_free(map->map);
			ft_putstr("map structure error\n");
			exit(1);
		}
		map->map[map->height] = line;
		map->height++;
	}
}

void	check_wall_map_2(t_map *map)
{
	if (!map->map[0])
	{
		ft_putstr("map empty :(\n");
		exit(1);
	}
	if (check_char(map, 'P') > 1 || check_char(map, 'P') == 0)
	{
		ft_free(map->map);
		ft_putstr("Player error !");
		exit(1);
	}
	if (check_char(map, 'C') == 0)
	{
		ft_free(map->map);
		ft_putstr("Collect error !");
		exit(1);
	}
	if (check_char(map, 'E') == 0)
	{
		ft_free(map->map);
		ft_putstr("Exit error !");
		exit(1);
	}
}

void	check_wall_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 || j == 0 || j == map->width - 1 || i == map->height - 1)
			{
				if (map->map[i][j] != '1')
				{	
					ft_free(map->map);
					ft_putstr("error map");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
	check_wall_map_2(map);
}

void	parsing_map(char *file, t_map *map)
{
	char	*path;
	int		fd;
	int		i;

	i = 0;
	path = ft_strjoin("assets/maps/", file);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error read map\n");
		exit(1);
	}
	map->map = malloc(sizeof(char *) * (map->height + 1));
	map->map[map->height + 1] = NULL;
	check_map(path, map);
	free(path);
	check_wall_map(map);
}

void	check_extension_map(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 1] != 'r' || map[i - 2] != 'e'
		|| map[i - 3] != 'b' || map[i - 4] != '.')
	{
		ft_putstr("error map\n");
		exit(1);
	}
}
