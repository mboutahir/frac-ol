# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 17:32:18 by mboutahi          #+#    #+#              #
#    Updated: 2025/04/05 13:27:45 by mboutahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c utils.c fractol_init.c map_scale.c render.c events.c

CC = cc

CFLAGS= -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o:%.c fractol.h
	${CC} ${CFLAGS} -Imlx -c $< -o $@

clean: 
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}
	
re: fclean all