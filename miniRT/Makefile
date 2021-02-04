DIR_HEADER	= ./includes

DIR_SRCS	= ./srcs/

SRC			= 	utils/error 	\
				math/vector.c \
				schena/camera.c \
				figures/sphare.c \
				ray_tracing/traice_ray \
				intersections/sphere_intersect.c \ #формула (квадратное уравнение) пересечения луча со сферой
				main.c \

SRCS		= $(addprefix $(DIR_SRCS), $(SRC))

OBJS		= $(SRCS:.c=.o)

NAME		= miniRT

LIMBLX 		= libmlx.dylib

GCC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra

%.o: %.
				$(GCC) $(CFLAGS) -I $(DIR_HEADER) -c $< -o $@

$(NAME):	$(OBJS)
					make -C ./minilibx_mms_20200219
					cp ./minilibx_mms_20200219/libmlx.dylib .
					$(GCC) $(CFLAGS) -I $(DIR_HEADER) $(LIMBLX) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
					$(RM) $(OBJS)

fclean:		clean
				make clean -C ./minilibx_mms_20200219
				$(RM) $(LIMBLX)
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
