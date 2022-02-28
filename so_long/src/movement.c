/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 04:28:50 by slammari          #+#    #+#             */
/*   Updated: 2022/02/22 18:32:14 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == 53)
		exit (1);
	if (keycode == 13 || keycode == 126)
		movement(map, map->x - 1, map->y);
	if (keycode == 2 || keycode == 124)
		movement(map, map->x, map->y + 1);
	if (keycode == 0 || keycode == 123)
		movement(map, map->x, map->y - 1);
	if (keycode == 1 || keycode == 125)
		movement(map, map->x + 1, map->y);
	return (0);
}

void	movement2(t_map *map, int x, int y)
{
	map->map[map->x][map->y] = '0';
	map->x = x;
	map->y = y;
	map->map[x][y] = 'P';
	print_map(map);
	map->count_move++;
}

void	movement(t_map *map, int x, int y)
{
	if (x < map->height && y < map->width)
	{
		if (map->map[x][y] != '1')
		{
			if (map->map[x][y] == 'E')
			{
				if (check_char(map, 'C') == 0)
					exit(1);
			}
			else
			{
				map->map[map->x][map->y] = '0';
				map->x = x;
				map->y = y;
				map->map[x][y] = 'P';
				print_map(map);
				map->count_move++;
				ft_putnbr(map->count_move);
				write(1, "\n", 1);
			}
		}
	}
}
