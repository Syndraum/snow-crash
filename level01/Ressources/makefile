NAME	= brute

SRCS	= brute.c
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

all:		${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -lcrypt -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all