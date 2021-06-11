SRCS =	push_swap.c push_swap_utils.c split.c func_lst.c ps_operat_p1.c ps_operat_p2_pu.c \
		clear_memory.c sort_chek_arr.c solver.c small_solve.c solver_utils.c \
		clear_dupl.c \
		temp.c
#BONUS =	

OBJS = ${SRCS:.c=.o}

#BONUS_OBJS = ${BONUS:.c=.o}

NAME = push_swap

HEADER = head_push_swap.h

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

# COLORS

GREEN = \033[0;32m
YELO = \033[0;33m
BLUE = \033[0;34m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re bonus

%.o:%.c	
			@${CC} ${CFLAGC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC} ${CFLAGC} -o ${NAME} ${OBJS}
			@echo "${GREEN}Project compile!${SHALLOW}"

#bonus:		

all:		${NAME}

clean:		
			@${RM} ${OBJS}
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${NAME}
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all 