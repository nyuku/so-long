# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angela <angela@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 00:00:00 by angnguye          #+#    #+#              #
#    Updated: 2023/04/08 03:22:41 by angela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------- Nickname --------------
NAME			= so_long
RM				= rm -f
CC				= gcc

# ---------------- FLAGS --------------
CFLAGS			= -Wall -Wextra -Werror -g  -Imlx -w #-fsanitize=address
MLXFLAGS 		= -Lmlx -lmlx -framework OpenGL -framework AppKit

# ---------------- Sources -----------
SRC				= ./src/so_long.c \
				 ./src/ft_printf/ft_printf.c \
				 ./src/gnl/get_next_line.c \
				 ./src/gnl/get_next_line_utils.c \
				 ./src/ft_printf/s_c_p_d_i.c \
				 ./src/ft_printf/u_x_X.c \
				 ./src/info_map.c \
				 ./src/key_hook.c \
				 ./src/decor_init.c \
				 ./src/render.c \
				 ./src/move.c \
				 ./src/game_init.c \
				 ./src/path_finding.c 

LIB				= ./includes/so_long.h
MAKEMLX			= ${MAKE} -C ${MLX}
MLX				= ./mlx/

# ---------------- Objets -----------
OBJS			= ${SRC:.c=.o}

# --------------- Regles --------------------
all:			${NAME}
${NAME}:		${OBJS}
				${MAKEMLX}
				${CC} ${CFLAGS} ${MLXFLAGS} -o ${NAME} ${OBJS}

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

run:
				./${NAME} map/simple_map.ber

# --------------- Service nettoyage --------------------
clean:
				${RM} ${OBJS}
				${MAKEMLX} clean


fclean:			clean
				${RM} ${NAME}
				# ${MAKEMLX} fclean

re:				fclean all

norm :
				# @norminette ${SRC}
				@norminette ${LIB}

.PHONY : all clean fclean re norm

