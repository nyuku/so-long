# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 00:00:00 by angnguye          #+#    #+#              #
#    Updated: 2023/04/23 00:28:14 by angnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------- Nickname --------------
NAME			= so_long
RM				= rm -f
CC				= gcc
# ---------------- Color --------------
GREEN			=		\033[1;32m
DARKGRAY		=		\033[1;30m
LIGHTGRAY		=		\033[1;37m
PURPLE			=		\033[0;35m
LIGHTPURPLE		=		\033[1;35m
LIGHTCYAN		=		\033[1;36m
LILAC			= 		\033[0;94m    
ENDCOLOR		=		\033[0m
# ---------------- Messages --------------
CLEAN_MSG		=		echo "$(DARKGRAY)Feed the bin 🗑️, Deleting objects$(ENDCOLOR)"
FCLEAN_MSG		=		echo "$(LIGHTGRAY)Deleting program❌$(ENDCOLOR)"
START_MSG		=		echo "$(LILAC)Compilation of $(NAME) done 🤟$(ENDCOLOR)"
CHARG_LINE_MSG	=		echo "$(LIGHTCYAN    $(ENDCOLOR)\c"
# ---------------- FLAGS --------------
CFLAGS			= -Wall -Wextra -Werror -g  -Imlx -w -fsanitize=address
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
				 ./src/path_finding.c \
				 ./src/error.c \
				 ./src/check_map.c \
				 ./src/check_map_pec01.c

LIB				= ./includes/so_long.h
MAKEMLX			= ${MAKE} -C ${MLX}
MLX				= ./mlx/

# ---------------- Objets -----------
OBJS			= ${SRC:.c=.o}

# --------------- Regles --------------------

all:			start ${NAME}	

${NAME}:		${OBJS}
				@${MAKEMLX}
				@${CC} ${CFLAGS} ${MLXFLAGS} -o ${NAME} ${OBJS}

.c.o:
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

run:
				@./${NAME} map/simple_map.ber
# --------------- VISUEL --------------------
BS_TXT			= echo "\n\n\n\n"
start:
				@$(BS_TXT)
				@tput setaf 92; cat ascii_art/cat_make; tput setaf default
				@$(BS_TXT)





# --------------- Service nettoyage --------------------
clean:
				@$(BS_TXT)
				@tput setaf 128; cat ascii_art/cat_clean; tput setaf default
				@$(BS_TXT)
				@${RM} ${OBJS}
				@${MAKEMLX} clean


fclean:			clean
				@tput setaf 189; cat ascii_art/cat_fclean; tput setaf default
				@$(BS_TXT)	
				@${RM} ${NAME}
				@# ${MAKEMLX} fclean
				@echo "$(GREEN)Cleaning succes🌸$(ENDCOLOR)"

re:				fclean all 
				@tput setaf 183; cat ascii_art/cat; tput setaf default
				@$(BS_TXT)

norm :
				@norminette ${SRC}
				@norminette ${LIB}
				@echo "$(PURPLE)Nooooorminetto$(ENDCOLOR)"
				@$(BS_TXT)

.PHONY : all clean fclean re norm

