FOLDER_UTILS		= utils

FOLDER_ROUTINE		= routine

SRCS				= philo.c

SRCS_UTILS			= ${addprefix ${FOLDER_UTILS}/,error_checking.c utils.c memory_utils.c}

SRCS_ROUTINE		= ${addprefix ${FOLDER_ROUTINE}/,routine_init.c routine_eat.c routine_sleep.c routine_think.c}

OBJS				= ${SRCS:.c=.o} ${SRCS_UTILS:.c=.o} ${SRCS_ROUTINE:.c=.o}

INCLUDES			= philo.h philo_struct.h ${FOLDER_UTILS}/utils.h ${FOLDER_ROUTINE}/routine.h

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
			@rm -f *.o ${FOLDER_UTILS}/*.o ${FOLDER_ROUTINE}/*.o
			@echo files cleaned !

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re