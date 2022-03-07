# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 15:59:26 by dokkim            #+#    #+#              #
#    Updated: 2022/03/07 18:27:10 by dokkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
OS			= Mac

CC			= gcc
CFLAGS		= $(INCFLAGS) $(WFLAGS) #$(GFLAGS)
WFLAGS		= -Wall -Wextra -Werror
GFLAGS		= -g3 -fsanitize=address
INCDIR		= includes
INCFLAGS	= -I$(INCDIR)

ifeq ($(OS), Linux)
	MLXFLAGS = -lmlx -lbsd -lXext -lX11
else
	MLXFLAGS = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
endif

MLXDIR		= minilibx_mms_20210621

ifeq ($(OS), Mac)
	MLX		= $(MLXDIR)/libmlx.dylib
endif

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

DRAW_SRCS		= $(addprefix ./srcs/draw/, \
 					draw_utils.c \
					draw.c \
					draw_line.c \
					calculate.c \
					image.c \
					set_player.c \
 					)

 EVENT_SRCS		= $(addprefix ./srcs/event/, \
 					event.c \
 					)

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
	$(CC) $(OBJS) $(CFLAGS)  $(MLXFLAGS) -o $@ -lm

$(MLX)		:
	make -C $(MLXDIR) all

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
