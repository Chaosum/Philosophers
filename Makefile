FOLDER_UTILS		= utils

SRCS				= philo.c

SRCS_UTILS			= ${addprefix ${FOLDER_UTILS}/,error_checking.c utils.c}

OBJS				= ${SRCS:.c=.o} ${SRCS_UTILS:.c=.o}

INCLUDES			= philo.h philo_struct.h ${FOLDER_UTILS}/utils.h

NAME				= philo

CC					= gcc

CFLAGS				= #-g3 -fsanitize=address -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.c
			${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
				gcc ${CFLAGS} -o ${NAME} ${OBJS} -lpthread
				@echo compilation complete !
			

${OBJS}:	${INCLUDES}

clean:
			@rm -f *.o
			@echo files cleaned !

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re