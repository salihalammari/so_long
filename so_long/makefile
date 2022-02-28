# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slammari <slammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 04:24:18 by slammari          #+#    #+#              #
#    Updated: 2022/02/27 20:21:00 by slammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

FRAME = -lmlx -framework OpenGL -framework AppKit

SRC = src/so_long.c src/movement.c src/print_map.c src/map_validate.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src/ft_putnbr.c src/free_map.c
SRC_BONUS = bonus/so_long_bonus.c bonus/movement_bonus.c bonus/print_map_bonus.c bonus/map_validate_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c bonus/ft_itoi_bonus.c bonus/free_map_bonus.c

INC = src/so_long.h
INC_BONUS = bonus/so_long_bonus.h

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ) $(INC)
	gcc $(CFLAGS) $(FRAME) $(OBJ) -o $(NAME)

bonus : $(OBJ_BONUS) $(INC_BONUS)
	gcc $(CFLAGS) $(FRAME) $(OBJ_BONUS) -o $(NAME)

clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all