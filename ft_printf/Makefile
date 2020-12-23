

NAME = libftprintf.a

SRCS =	ft_printf.c 

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

GCC = gcc

HEADER = ft_printf.h

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
					make -C ./libft/
					cp libft/libft.a
					mv libft.a ${NAME}
					ar rc ${NAME} ${OBJS}

%.o:%.c ${HEADER}
				gcc ${CFLAGS} $< -o $@

all: ${NAME}

clean:
				rm -f ${OBJS}

fclean: clean
	 			rm -f ${NAME}
				make fclean -C ./libft/

re:			fclean all

.PHONY: all clean fclean bonus re
