SRCS_CLIENT =	client.c minitalk_utils.c
SRCS_SERVER =	server.c minitalk_utils.c
SRCS_CLIENT_B =	client_bonus.c minitalk_utils1_bonus.c minitalk_utils2_bonus.c
SRCS_SERVER_B =	server_bonus.c minitalk_utils1_bonus.c minitalk_utils2_bonus.c

SRCS_DIR =		./srcs/
SRCS_DIR_B =	./srcs_bonus/


OBJS_CLIENT =	${addprefix ${SRCS_DIR}, ${SRCS_CLIENT:.c=.o}}
OBJS_SERVER =	${addprefix ${SRCS_DIR}, ${SRCS_SERVER:.c=.o}}
OBJS_CLIENT_B =	${addprefix ${SRCS_DIR_B}, ${SRCS_CLIENT_B:.c=.o}}
OBJS_SERVER_B =	${addprefix ${SRCS_DIR_B}, ${SRCS_SERVER_B:.c=.o}}

NAME_CLIENT =	client
NAME_SERVER =	server
NAME_CLIENT_B =	client_b
NAME_SERVER_B =	server_b

HEADER =	./srcs/head_minitalk.h
HEADER_B =	./srcs_bonus/head_minitalk_bonus.h

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

all:		${NAME_CLIENT} ${NAME_SERVER}

%.o:%.c	
			@${CC} ${CFLAGC} -c $< -o ${<:.c=.o}

${NAME_CLIENT}:	${OBJS_CLIENT} ${HEADER}
				@${CC} ${CFLAGC} -o ${NAME_CLIENT} ${OBJS_CLIENT}
				@echo "${GREEN}${NAME_CLIENT} compile!${SHALLOW}"

${NAME_SERVER}:	${OBJS_SERVER} ${HEADER}
				@${CC} ${CFLAGC} -o ${NAME_SERVER} ${OBJS_SERVER}
				@echo "${GREEN}${NAME_SERVER} compile!${SHALLOW}"

bonus:	${NAME_CLIENT_B} ${NAME_SERVER_B}

${NAME_CLIENT_B}:	${OBJS_CLIENT_B} ${HEADER_B}
					@${CC} ${CFLAGC} -o ${NAME_CLIENT_B} ${OBJS_CLIENT_B}
					@echo "${NEW}${NAME_CLIENT_B} compile!${SHALLOW}"

${NAME_SERVER_B}:	${OBJS_SERVER_B} ${HEADER_B}
					@${CC} ${CFLAGC} -o ${NAME_SERVER_B} ${OBJS_SERVER_B}
					@echo "${NEW}${NAME_SERVER_B} compile!${SHALLOW}"

clean:		
			@${RM} ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS_CLIENT_B} ${OBJS_SERVER_B}
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS_CLIENT_B} ${OBJS_SERVER_B} ${NAME_CLIENT} ${NAME_SERVER} ${NAME_CLIENT_B} ${NAME_SERVER_B}
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all