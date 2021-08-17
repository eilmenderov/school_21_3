SRCS	=	pipex.c pipex_utils.c split.c
SRCS_B	=	pipex_bonus.c pipex_utils.c split.c get_next_line.c pipex_bonus_utils.c

SRCS_DIR	= ./srcs/

OBJS	= ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}
OBJS_B	= ${addprefix ${SRCS_DIR}, ${SRCS_B:.c=.o}}

NAME	= pipex
NAME_B	= pipex_bonus

HEADER	= ./srcs/head_pipex.h

CC = gcc -g
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

# COLORS

GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re norm bonus

all:		${NAME}

%.o:%.c		${HEADER}
			@${CC} ${CFLAGC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC} ${CFLAGC} -o ${NAME} ${OBJS}
			@echo "${GREEN}${NAME} compile!${SHALLOW}"

bonus:		${OBJS_B} ${HEADER}
			@${CC} ${CFLAGC} -o ${NAME_B} ${OBJS_B}
			@echo "${NEW}${NAME_B} compile!${SHALLOW}"

norm:
			@echo "${GREEN}|-----Chek NORMs!-----|${NEW}"
			@norminette ${SRCS_DIR}
			@echo "${GREEN}|-----Chek ended!-----|${SHALLOW}"

clean:		
			@${RM} ${OBJS} ${OBJS_B}
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${NAME} ${OBJS_B} ${NAME_B}
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all
