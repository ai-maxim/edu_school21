# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdong <qdong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 14:53:25 by qdong             #+#    #+#              #
#    Updated: 2021/04/14 16:37:39 by qdong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_HEADER	= ./includes/

DIR_SRCS	= ./srcs/

SRC			= 	utils/error_exit.c utils/strlen_arr.c utils/window.c\
				utils/colors.c utils/color_intens.c utils/bmp.c\
				math/vector.c math/normal.c \
				main.c \
				libft/ft_strlen.c libft/ft_substr.c libft/ft_split.c \
				libft/get_next_line.c libft/get_next_line_utils.c \
				libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_isascii.c\
				libft/ft_lstadd_back.c libft/ft_strchr.c \
				libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_lstlast.c \
				libft/ft_atoi.c libft/ft_atof.c libft/ft_bzero.c\
				parsers/pars_data.c parsers/parse_r.c \
				parsers/parse_a.c parsers/parse_c.c \
				parsers/parse_l.c parsers/parse_pl.c \
				parsers/parse_sp.c parsers/parse_sq.c \
				parsers/parse_cy.c parsers/parse_tr.c \
				ray_tracing/traice_ray.c \
				intersections/sp_intersect.c  \
				intersections/pl_intersect.c \
				intersections/cy_intersect.c \
				intersections/tr_intersect.c \

SRCS		= $(addprefix $(DIR_SRCS), $(SRC))

OBJS		= $(SRCS:.c=.o)

NAME		= miniRT

LIMBLX 		= libmlx.dylib

GCC			= gcc -g
RM			= rm -f
# CFLAGS		= -Wall -Werror -Wextra

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


				# intersections/intersect.c \
				# intersections/sq_intersect.c \


