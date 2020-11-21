

NAME = libftprintf.a

SRCS = ft_atoi.c ft_itoa.c

CFLAGS = -Wall -Werror -Wextra -c

SRCS_BONUS =

OBJS = $(SRCS)

HEADER = ft_print.h

all: $(NAME)

$(NAME):	$(OBJS)
					ar rcs $(NAME) $(OBJS)

%.o:%.c $(HEADER)
				gcc $(CFLAGS) $< -o $@

clean:
			rm -f $(OBJS)

fclean: clean
	 			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re					
