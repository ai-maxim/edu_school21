# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdong <qdong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 14:56:09 by qdong             #+#    #+#              #
#    Updated: 2021/01/10 16:03:50 by qdong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c			\
		printing.c			\
		pars_modifiers.c	\
		parsers.c			\
		putstr_chec.c		\
		reset_flags.c		\
		itoa_base2.c			\
		print_str.c			\
		print_char.c		\
		print_procent.c		\
		print_deci.c		\
		print_unsig_deci.c	\
		print_x.c			\
		print_pointer.c

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

GCC = gcc

HEADER = ft_printf.h

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
					make -C ./libft/
					cp libft/libft.a ./
					mv libft.a ${NAME}
					ar rc ${NAME} ${OBJS}

%.o:%.c ${HEADER}
				gcc ${CFLAGS} -c $< -o $@

all: ${NAME}

clean:
				rm -f ${OBJS}

fclean: clean
				rm -f ${NAME}
				make fclean -C ./libft/

re:			fclean all

.PHONY: all clean fclean bonus re
