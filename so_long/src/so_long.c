/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 04:29:28 by slammari          #+#    #+#             */
/*   Updated: 2022/02/27 20:21:08 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_read(int fd, char **line)
{
	*line = get_next_line(fd);
	return (*line);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = ("null");
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
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
	map.img = &img;
	print_map(&map);
	map.count_move = 0;
	mlx_hook(mlx.win, 2, 0, &key_press, &map);
	mlx_hook(mlx.win, 17, 0, &ft_close, &map);
	mlx_loop(mlx.mlx_ptr);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(av[1]);
	else
		ft_putstr("error syntaxe\n");
}
