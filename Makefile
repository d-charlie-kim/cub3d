# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaejeong <jaejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 15:59:26 by dokkim            #+#    #+#              #
#    Updated: 2022/03/03 13:52:24 by jaejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
OS			= Mac

CC			= gcc
CFLAGS		= $(INCFLAGS) $(WFLAGS) #$(GFLAGS)
WFLAGS		= -Wall -Wextra -Werror
GFLAGS		= -g -fsanitize=address
INCDIR		= includes
INCFLAGS	= -I$(INCDIR)

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

PARSE_SRCS		= $(addprefix ./srcs/parse/, \
					init_data.c \
					parsing.c \
					parse_utils.c \
					put_data.c \
					)

VALIDATE_SRCS	= $(addprefix ./srcs/validate/, \
					validate_data.c \
					)

# DRAW_SRCS		= $(addprefix ./srcs/draw/, \
# 					image.c \
# 					)

# EVENT_SRCS		= $(addprefix ./srcs/event/, \
# 					event.c \
# 					)

# MOVE_SRCS		= $(addprefix ./srcs/move/, \
# 					)

ERROR_SRCS		= $(addprefix ./srcs/error/, \
					ft_error.c \
					)

UTILS_SRCS		= $(addprefix ./srcs/utils/, \
					libft.c \
					)


SRCS		= ./srcs/main.c \
				$(GNL_SRCS) \
				$(PARSE_SRCS) \
				$(UTILS_SRCS) \
				$(ERROR_SRCS) \
				$(VALIDATE_SRCS) \
				$(DRAW_SRCS) \
				$(EVENT_SRCS) \

OBJS	= $(SRCS:.c=.o)

all			: $(NAME)

%.o		:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		: $(MLX) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@
# $(MLXFLAGS) 뺌

$(MLX)		:
	# make -C $(MLXDIR) all

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
