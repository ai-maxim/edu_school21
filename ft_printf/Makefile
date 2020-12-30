# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdong <qdong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 14:56:09 by qdong             #+#    #+#              #
#    Updated: 2020/12/28 15:19:49 by qdong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c			\
		ft_printing.c 		\
		ft_pars_modifiers.c \
		parsers.c 			\
		init_flags.c 		\
		ft_strlen.c			\
		print_str.c			\
		print_char.c

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
