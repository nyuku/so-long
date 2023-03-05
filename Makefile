# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 22:22:18 by angnguye          #+#    #+#              #
#    Updated: 2023/03/04 23:51:19 by angnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------- Nickname --------------
NAME			= so_long
RM				= rm -f
CC				= gcc

# ---------------- FLAGS --------------
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address -Imlx -w
MLXFLAGS 		= -Llib/mlx -lmlx -framework OpenGL -framework AppKit

# ---------------- Sources -----------
SRC				= ./main.c
LIB				= ./includes/so_long.h
MAKEMLX			= ${MAKE} -C ${MLX}
MLX				= ./mlx/

# ---------------- Objets -----------
OBJS			= ${SRC:.c=.o}

# --------------- Regles --------------------
all:			${NAME}
${NAME}:		${OBJS}
				${MAKEMLX}
				${CC} ${CFLAGS} ${MLXFLAGS} -o ${NAME} ${OBJS} && ./${NAME}
				
				
				# gcc -Wall -Wextra -Werror -g -fsanitize=address -Imlx -w  -Llib/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
			
.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}



# --------------- Service nettoyage --------------------
clean:
				${RM} ${OBJS}
				${MAKEMLX} clean


fclean:			clean
				${RM} ${NAME}
				${MAKEMLX} fclean

re:				fclean all

norm :
				# @norminette ${SRC}
				@norminette ${LIB}

.PHONY : all clean fclean re norm

