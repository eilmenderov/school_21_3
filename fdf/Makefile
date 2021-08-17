SRCS =	main.c fdf_utils.c get_next_line.c read_map.c split.c draw_img.c color.c draw_utils.c pool_st_end.c

BONUS =	main_bonus.c fdf_utils_bonus.c get_next_line_bonus.c read_map_bonus.c split_bonus.c draw_img_bonus.c \
		color_bonus.c draw_utils_bonus.c pool_st_end_bonus.c

SRCS_DIR = ./srcs/
SRCS_BONUS_DIR = ./srcs_bonus/

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

BONUS_OBJS = ${addprefix ${SRCS_BONUS_DIR}, ${BONUS:.c=.o}}

NAME = fdf

B_NAME = fdf_bonus

HEADER = ./srcs/head_fdf.h

B_HEADER = ./srcs_bonus/head_fdf_bonus.h

MLX_LIBS = -lmlx -lm -L ./minilibx_siera -framework OpenGL -framework AppKit

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

# COLORS

GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re bonus

all:		minilibx ${NAME}

minilibx:	Makefile
			@${MAKE} -sC ./minilibx_siera

%.o:%.c		${HEADER}
			@${CC} ${CFLAGC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC} ${CFLAGC} -o ${NAME} -I head_fdf.h ${OBJS} ${MLX_LIBS}
			@echo "${GREEN}${NAME} compile!${SHALLOW}"

bonus:		${BONUS_OBJS} ${B_HEADER}
			@${CC} ${CFLAGC} -o ${B_NAME} -I head_fdf_bonus.h ${BONUS_OBJS} ${MLX_LIBS}
			@echo "${NEW}${B_NAME} compile!${SHALLOW}"

clean:		
			@${RM} ${OBJS} ${BONUS_OBJS}
			@make -C minilibx_siera/ clean
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${BONUS_OBJS} ${NAME} ${B_NAME}
			@make -C minilibx_siera/ clean
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all