/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 04:31:19 by slammari          #+#    #+#             */
/*   Updated: 2022/02/28 14:52:07 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*init_image(char *file, t_mlx *mlx)
{
	void	*image;
	int		width;
	int		height;

	width = 0;
	height = 0;
	image = mlx_xpm_file_to_image(mlx->mlx_ptr, file, &width, &height);
	if (width == 0 || width == 0)
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
	img->player2 = init_image("assets/img/player2.xpm", mlx);
	img->exit = init_image("assets/img/exit.xpm", mlx);
	img->enemy1 = init_image("assets/img/enemy1.xpm", mlx);
	img->enemy2 = init_image("assets/img/enemy2.xpm", mlx);
}

void	print_map2(t_map *map, int *i, char *player, char *enemy)
{
	if (map->map[i[0]][i[1]] == 'P')
	{
		map->x = i[0];
		map->y = i[1];
		mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
			player, i[1] * 50, i[0] * 50);
	}
	if (map->map[i[0]][i[1]] == 'E')
	{
		mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
			map->img.exit, i[1] * 50, i[0] * 50);
	}
	if (map->map[i[0]][i[1]] == 'C')
		mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
			map->img.collect, i[1] * 50, i[0] * 50);
	if (map->map[i[0]][i[1]] == 'M')
	{
		mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
			enemy, i[1] * 50, i[0] * 50);
	}
}

void	print_map(t_map *map, char *player, char *enemy)
{
	int	i[2];

	i[0] = 0;
	while (i[0] < map->height)
	{
		i[1] = 0;
		while (i[1] < map->width)
		{
			if (map->map[i[0]][i[1]] == '1')
				mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
					map->img.wall, i[1] * 50, i[0] * 50);
			if (map->map[i[0]][i[1]] == '0' || map->map[i[0]][i[1]] == 'E'
				|| map->map[i[0]][i[1]] == 'P')
				mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win,
					map->img.floor, i[1] * 50, i[0] * 50);
			print_map2(map, i, player, enemy);
			(i[1])++;
		}
		(i[0])++;
	}
}

int	ft_close(void)
{
	exit(1);
	return (0);
}
