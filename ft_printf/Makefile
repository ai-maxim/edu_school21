

NAME = libftprintf.a

NAME_LIBFT = libft.a

SRCS =	ft_printf.c
				./libft/ft_itoa.c ./libft/ft_strlen.c \
				./libft/ft_strdup.c ./libft/ft_substr.c \
				./libft/ft_calloc.c ./libft/ft_bzero.c \
				./libft/ft_putchar.c ./libft/ft_

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

GCC = gcc

HEADER = ft_printf.h

// RM = rm -f

LIBFT_DIR = libft/

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
					make -C ${LIBFT_DIR}
					cp ${LIBFT_DIR}libft.a ./
					mv ${NAME_LIBFT} ${NAME}
					ar -rc ${NAME} ${OBJS}
					
%.o:%.c ${HEADER}
				gcc ${CFLAGS} $< -o $@

all: ${NAME}

clean:
			rm -f ${OBJS}

fclean: clean
	 			rm -f ${NAME}
				make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean bonus re
