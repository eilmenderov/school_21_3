SRCS =	push_swap.c push_swap_utils.c split.c func_lst.c ps_operat_p1.c ps_operat_p2_pu.c \
		clear_memory.c sort_chek_arr.c small_solve.c solver_utils_p1.c solver_utils_p2.c \
		first_step.c second_step.c solver.c

BONUS =	split.c func_lst.c ps_operat_p1.c ps_operat_p2_pu.c clear_memory.c checker_utils.c \
		push_swap_utils.c solver_utils_p1.c solver_utils_p2.c get_next_line.c sort_chek_arr.c \
		checker.c 

SRCS_DIR = srcs/

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

BONUS_OBJS = ${addprefix ${SRCS_DIR}, ${BONUS:.c=.o}}

NAME = push_swap

B_NAME = checker

HEADER = ${addprefix ${SRCS_DIR}, head_push_swap.h}

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

%.o:%.c		${HEADER}
			@${CC} ${CFLAGC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC} ${CFLAGC} -o ${NAME} ${OBJS}
			@echo "${GREEN}push_swap compile!${SHALLOW}"

bonus:		${BONUS_OBJS} ${HEADER}
			@${CC} ${CFLAGC} -o ${B_NAME} ${BONUS_OBJS}
			@echo "${NEW}checker compile!${SHALLOW}"

all:		${NAME} bonus

clean:		
			@${RM} ${OBJS} ${BONUS_OBJS}
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${BONUS_OBJS} ${NAME} ${B_NAME}
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all 