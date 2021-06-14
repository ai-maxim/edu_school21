# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdong <qdong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 14:25:42 by qdong             #+#    #+#              #
#    Updated: 2021/06/14 19:26:08 by qdong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = 	server
NAME1_SRCS = server.c

NAME2 = client
NAME2_SRCS = client.c

SRCS =	ft_strlen.c \
		ft_putchar.c \
		ft_putstr.c	\
		ft_putnbr.c	\
		ft_atoi.c	\

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}
NAME1_OBJS = ${NAME1_SRCS:.c=.o}
NAME2_OBJS = ${NAME2_SRCS:.c=.o}

HEADER = minitalk.h

.c.o:
			@gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${CLIENT} :${NAME1_OBJS}
		@gcc $(CFLAGS) $(NAME1_OBJS) ${OBJS} -o ${CLIENT}

${SERVER} :${NAME2_OBJS}
		@gcc $(CFLAGS) $(NAME2_OBJS) ${OBJS} -o ${SERVER}

%.o:%.c ${HEADER}
		gcc ${CFLAGS} -c $< -o $@

all: ${OBJS} ${CLIENT} ${SERVER}

clean:
		rm -f ${OBJS} ${NAME1_OBJS} ${NAME2_OBJS}

fclean:	clean
				re -f ${CLIENT} ${SERVER}

re:		fclean all

.PHONY: all clean fclean re
