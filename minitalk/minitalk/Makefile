NAME1 = server
NAME1_SRCS = server.c

NAME2 = client
NAME2_SRCS = client.c

SRCS =	ft_putchar.c \
		ft_putstr.c	\
		ft_putnbr.c	\
		ft_atoi.c

CFLAGS = -Wall -Werror -Wextra

NAME1_OBJS = ${NAME1_SRCS:.c=.o}
NAME2_OBJS = ${NAME2_SRCS:.c=.o}
OBJS = ${SRCS:.c=.o}

HEADER = minitalk.h

all: 	${OBJS} ${NAME2} ${NAME1}

${NAME1} :${NAME1_OBJS}
		@gcc $(CFLAGS) $(NAME1_OBJS) ${OBJS} -o ${NAME1}

${NAME2} :${NAME2_OBJS}
		@gcc $(CFLAGS) $(NAME2_OBJS) ${OBJS} -o ${NAME2}

%.o:%.c ${HEADER}
		@gcc ${CFLAGS} -c $< -o $@

clean:
		rm -f ${OBJS} ${NAME1_OBJS} ${NAME2_OBJS}

fclean:	clean
		rm -f ${NAME2} ${NAME1}

re:		fclean all

.PHONY: all clean fclean re
