# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdong <qdong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 14:56:09 by qdong             #+#    #+#              #
#    Updated: 2021/01/07 22:32:45 by qdong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c			\
		ft_printing.c 		\
		pars_modifiers.c \
		parsers.c 			\
		ft_done_width.c		\
		ft_putstr_chec.c	\
		reset_flags.c	\
		print_str.c			\
		print_char.c	\
		print_procent.c		\
		print_deci.c	\
		print_unsig_deci.c

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
