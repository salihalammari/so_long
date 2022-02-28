/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 04:29:06 by slammari          #+#    #+#             */
/*   Updated: 2022/02/28 14:53:09 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*init_image(char *file, t_mlx *mlx)
{
	void	*image;
	int		width;
	int		height;

	width = 0;
	height = 0;
	image = mlx_xpm_file_to_image(mlx->mlx_ptr, file, &width, &height);
	if (width == 0 || height == 0)
	{
		ft_putstr("error img");
		exit(1);
	}
	return (image);
}

void	init_images(t_mlx *mlx, t_img *img)
{
	img->floor = init_image("assets/img/floor.xpm", mlx);
	img->collect = init_image("assets/img/collect.xpm", mlx);
	img->wall = init_image("assets/img/wall.xpm", mlx);
	img->player1 = init_image("assets/img/player1.xpm", mlx);
	img->exit = init_image("assets/img/exit.xpm", mlx);
}

void	print_map2(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'P')
	{
		map->x = i;
		map->y = j;
		mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
			map->img->player1, j * 50, i * 50);
	}
	if (map->map[i][j] == 'E')
	{
		mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
			map->img->exit, j * 50, i * 50);
	}
	if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
			map->img->collect, j * 50, i * 50);
	if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
			map->img->floor, j * 50, i * 50);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
					map->img->wall, j * 50, i * 50);
			if (map->map[i][j] == '0' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'P' || map->map[i][j] == 'C')
				print_map2(map, i, j);
			j++;
		}
		i++;
	}
}

int	ft_close(t_map *map)
{
	ft_free(map->map);
	exit(1);
	return (0);
}
