# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 13:21:14 by lumarque          #+#    #+#              #
#    Updated: 2023/09/06 17:28:00 by lumarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c #src/utils.c src/create_map.c src/clean_exit.c \
		src/check_map.c src/graphics.c src/moves.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libs/libft
MLX_PATH = libs/minilibx-linux
LIBFT = -L ${LIBFT_PATH} -lft
MLX	= -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm 

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${MAKE} ${LIBFT_PATH}
		${MAKE} ${MLX_PATH}
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

all:	${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${MAKE} ${MLX_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re