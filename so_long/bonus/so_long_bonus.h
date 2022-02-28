/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:27:52 by slammari          #+#    #+#             */
/*   Updated: 2022/02/27 20:07:47 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*wall;
	void	*player1;
	void	*player2;
	void	*collect;
	void	*exit;
	void	*floor;
	void	*enemy1;
	void	*enemy2;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	t_img	img;
	t_mlx	mlx;
	int		x;
	int		y;
	int		count_move;
}	t_map;

void	check_extension_map(char *map);
void	parsing_map(char *file, t_map *map);
void	check_map(char *file, t_map	*map);
int		ft_strlen_nl(char *str);
void	ft_error(void);
void	ft_putstr(char *str);
void	check_wall_map(t_map *map);
int		check_char(t_map *map, char c);
int		key_press(int keycode, t_map *map);
void	movement(t_map *map, int x, int y);
void	print_map(t_map *map, char *player, char *enemy);
void	init_images(t_mlx *mlx, t_img *img);
char	*ft_read(int fd, char **line);
char	*ft_itoa(int n);
int		ft_close(void);
int		loop_player(t_map *map);
void	count_screen(t_map *map);
void	ft_free(char **map);

#endif
