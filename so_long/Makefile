SRCS		=	so_long.c so_long_utils.c parser.c start_game.c moves.c

BONUS		=	so_long_bonus.c so_long_utils.c parser.c start_game.c moves.c

SRCS_DIR	= ./srcs/

OBJS		= ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

BONUS_OBJS	= ${addprefix ${SRCS_DIR}, ${BONUS:.c=.o}}

NAME		= so_long

B_NAME		= so_long_bonus

HEADER		= ./srcs/head_so_long.h

B_HEADER	= ./srcs/head_so_long_bonus.h

MLX_LIBS	= -lmlx -lm -L ./minilibx_opengl -framework OpenGL -framework AppKit

LIB			=	./libft/libft.a

CC = gcc
RM = rm -f

CFLAGS		= -Wall -Wextra -Werror

# COLORS

GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re bonus norm libft minilibx

all:		${NAME}

minilibx:	
			${MAKE} -C ./minilibx_opengl 2> /dev/null

%.o:%.c		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:		
			${MAKE} -C ./libft/

${NAME}:	${OBJS} ${HEADER}
			${MAKE} -C ./libft/
			${MAKE} -C ./minilibx_opengl 2> /dev/null
			${CC} ${CFLAGS} -o ${NAME} -I ${HEADER} ${OBJS} ${LIB} ${MLX_LIBS}
			@echo "${GREEN}${NAME} compile!${SHALLOW}"

bonus:		${B_NAME}

${B_NAME}:	${BONUS_OBJS} ${HEADER}
			${MAKE} -C ./libft/
			${MAKE} -C ./minilibx_opengl 2> /dev/null
			${CC} ${CFLAGS} -o ${B_NAME} -I ${HEADER} ${BONUS_OBJS} ${LIB} ${MLX_LIBS}
			@echo "${NEW}${B_NAME} compile!${SHALLOW}"
norm:
			@echo "${GREEN}|-----Chek NORMs!-----|${NEW}"
			@norminette ./srcs/
			@norminette ./libft/
			@echo "${GREEN}|-----Chek ended!-----|${SHALLOW}"

clean:		
			@${RM} ${OBJS} ${BONUS_OBJS}
			@make clean -C ./libft/
			@make -C minilibx_opengl/ clean
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${BONUS_OBJS} ${NAME} ${B_NAME}
			@make fclean -C ./libft/
			@make -C minilibx_opengl/ clean
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all
