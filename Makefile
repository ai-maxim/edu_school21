SRCS = ft_memset.c ft_bzero.c ft_strlen.c ft_memcpy.c \
 ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c \
 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
 ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
 ft_strlcat.c ft_strnstr.c ft_calloc.c ft_atoi.c ft_strdup.c ft_strnstr.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Werror -Wextra 
OPTION = -c
RM = rm -f

NAME = libft.a

$(NAME):	
			$(CC) $(CFLAGS) $(OPTION) $(SRCS)
			ar rc $(NAME) *.o
			ranlib $(NAME)
			
all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
