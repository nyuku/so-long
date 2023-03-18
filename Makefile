# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 00:00:00 by angnguye          #+#    #+#              #
#    Updated: 2023/03/18 19:41:12 by angnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------- Nickname --------------
NAME			= so_long
RM				= rm -f
CC				= gcc

# ---------------- FLAGS --------------
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address -Imlx -w
MLXFLAGS 		= -Lmlx -lmlx -framework OpenGL -framework AppKit

# ---------------- Sources -----------
SRC				= ./src/so_long.c \
				 ./src/ft_printf/ft_printf.c \
				 ./src/gnl/get_next_line.c \
				 ./src/gnl/get_next_line_utils.c \
				 ./src/ft_printf/s_c_p_d_i.c \
				 ./src/ft_printf/u_x_X.c \
				 ./src/info_map.c \
				 ./src/key_hook.c 

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

