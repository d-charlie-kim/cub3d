# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 15:59:26 by dokkim            #+#    #+#              #
#    Updated: 2022/02/24 19:51:28 by dokkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
OS			= Mac

CC			= gcc
CFLAGS		= $(INCFLAGS) $(WFLAGS) #$(GFLAGS)
WFLAGS		= -Wall -Wextra -Werror
GFLAGS		= -g -fsanitize=address
INCDIR		= includes
INC			= -I $(INCDIR)

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

# DRAW_SRCS		= $(addprefix ./srcs/draw/, \
# 					)

PARSE_SRCS		= $(addprefix ./srcs/parse/, \
					map_parsing.c \
					map_utils.c \
					)

# MOVE_SRCS		= $(addprefix ./srcs/move/, \
# 					)

UTILS_SRCS		= $(addprefix ./srcs/utils/, \
					libft.c \
					)

# VALIDATE_SRCS	= $(addprefix ./srcs/validate/, \
# 					)

ERROR_SRCS		= $(addprefix ./srcs/error/, \
					ft_error.c \
					)

SRCS		= ./srcs/main.c \
				$(GNL_SRCS) \
				$(MAP_SRCS) \
				$(UTILS_SRCS) \
				$(ERROR_SRCS) \

OBJS	= $(SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(MLX) $(OBJS)
	$(CC) $(OBJS) $(INC) $(CFLAGS) -o $@
# $(MLXFLAGS) 뺌

$(MLX)		:
	# make -C $(MLXDIR) all

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re