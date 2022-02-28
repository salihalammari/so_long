/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:21:29 by slammari          #+#    #+#             */
/*   Updated: 2022/02/27 20:07:50 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_read(int fd, char **line)
{
	*line = get_next_line(fd);
	return (*line);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	count_screen(t_map *map)
{
	char	*str;
	char	*nb;

	str = "Moves : ";
	nb = ft_itoa(map->count_move);
	str = ft_strjoin(str, nb);
	mlx_string_put(map->mlx.mlx_ptr, map->mlx.win, 25, 15, 0xFFFFFF, str);
	free(str);
	free(nb);
}

void	so_long(char *path)
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;

	parsing_map(path, &map);
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr,
			(map.width * 50), (map.height * 50), "so_long");
	init_images(&mlx, &img);
	map.mlx = mlx;
	map.img = img;
	print_map(&map, map.img.player1, map.img.enemy1);
	map.count_move = 0;
	mlx_hook(mlx.win, 2, 0, &key_press, &map);
	mlx_loop_hook(mlx.mlx_ptr, &loop_player, &map);
	mlx_hook(mlx.win, 17, 0, &ft_close, NULL);
	mlx_loop(mlx.mlx_ptr);
	free (mlx.mlx_ptr);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(av[1]);
	else
		ft_putstr("error syntaxe\n");
}
