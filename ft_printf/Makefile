

NAME = libftprintf.a

SRCS =	ft_printf.c
				./libft/ft_itoa.c ./libft/ft_strlen.c \
				./libft/ft_strdup.c ./libft/ft_substr.c \
				./libft/ft_calloc.c ./libft/ft_bzero.c \
				./libft/ft_putchar.c ./libft/ft_

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
