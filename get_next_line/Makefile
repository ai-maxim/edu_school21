СС = gcc

NAME =

SRCS =

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=32

OBJS =	$(SRCS:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			ar rc $(NAME)

all:		$(NAME)

clean:
		rm -rf $(OBGS)

fclean:	clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
