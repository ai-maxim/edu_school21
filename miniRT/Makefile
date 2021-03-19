# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdong <qdong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 14:53:25 by qdong             #+#    #+#              #
#    Updated: 2021/03/19 20:28:42 by qdong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_HEADER	= ./includes/

DIR_SRCS	= ./srcs/

SRC			= 	utils/error_exit.c 	\
				math/vector.c \
				scena/camera.c scena/scena.c \
				figures/sfera.c figures/plane.c figures/cylinder.c \
				figures/square.c \
				ray_tracing/traice_ray.c \
				intersections/sfera_intersect.c  \
				intersections/plane_intersect.c \
				intersections/cylinder_intersect.c \
				intersections/sq_intersect.c \
				main.c \
				libft/ft_strlen.c libft/ft_substr.c libft/ft_split.c \
				libft/get_next_line.c libft/get_next_line_utils.c \
				libft/ft_strjoin.c libft/ft_strncmp.c \
				libft/ft_lstadd_back.c libft/ft_strchr.c \
				libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_lstlast.c \
				libft/ft_atoi.c libft/ft_atof.c \
				parsers/pars_data.c parsers/parse_r.c \
				parsers/parse_a.c parsers/parse_c.c \
				parsers/parse_l.c parsers/parse_pl.c \
				parsers/colors.c parsers/parse_sp.c \
				parsers/parse_sq.c parsers/parse_cy.c \
				parsers/parse_tr.c

SRCS		= $(addprefix $(DIR_SRCS), $(SRC))

OBJS		= $(SRCS:.c=.o)

NAME		= miniRT

LIMBLX 		= libmlx.dylib

GCC			= gcc -g
RM			= rm -f
#CFLAGS		= -Wall -Werror -Wextra

%.o: %.c
				$(GCC) $(CFLAGS) -I $(DIR_HEADER) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./mlx
			cp ./mlx/libmlx.dylib .
			$(GCC) $(CFLAGS) -I $(DIR_HEADER) $(LIMBLX) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
					$(RM) $(OBJS)

fclean:		clean
				make clean -C ./mlx
				$(RM) $(LIMBLX)
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
