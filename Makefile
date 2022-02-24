# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 15:59:26 by dokkim            #+#    #+#              #
#    Updated: 2022/02/24 16:00:05 by dokkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
OS			= Mac

CC			= gcc
CFLAGS		= $(INCFLAGS) $(WFLAGS) #$(GFLAGS)
GFLAGS		= -g -fsanitize=address
WFLAGS		= -Wall -Wextra -Werror
INC			= -I ./includes

ifeq ($(OS), Linux)
	MLXFLAGS = -lmlx -lbsd -lXext -lX11
else
	MLXFLAGS = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
endif

MLXDIR		= minilibx_opengl_20191021
MLX			= $(MLXDIR)/libmlx.a

GNL_SRCS		= $(addprefix ./srcs/get_next_line/, \
					get_next_line.c \
					get_next_line_utils.c \
					)

DRAW_SRCS		= $(addprefix ./srcs/draw/, \
					)

MAP_SRCS		= $(addprefix ./srcs/map/, \
					)

MOVE_SRCS		= $(addprefix ./srcs/move/, \
					)

UTILS_SRCS		= $(addprefix ./srcs/utils/, \
					)

VALIDATE_SRCS	= $(addprefix ./srcs/validate/, \
					)

SRCS		= ./srcs/main.c \

OBJS	= $(SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(MLX) $(OBJS)
	$(CC) $(OBJS) $(INC) $(CFLAGS) $(MLXFLAGS) -o $@

$(MLX)		:
	make -C $(MLXDIR) all

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re