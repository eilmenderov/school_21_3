SRCS =	push_swap.c push_swap_utils.c ft_split.c ft_func_lst.c ft_ps_operat_p1.c \
		ft_ps_operat_p2.c ft_clear_memory.c ft_sort_chek_arr.c ft_solver.c \
		ft_solver_utils.c ft_small_solve.c ft_improve_dec.c ft_duo_nb.c

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