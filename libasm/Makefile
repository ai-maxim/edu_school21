NAME = libasm.a
SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

OBJ = $(SRCS:%.s=%.o)

TEST = main.c

%.o: %.s
	nasm -f macho64 $<

$(NAME):	$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

all:		$(NAME)

run:		all
				@gcc main.c libasm.a -I libasm.h
				@./a.out

test:		gcc libasm.a main.c -I

clean:
			@rm -f *.o
			@rm -f ./a.out
			@rm -f ./*txt

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
