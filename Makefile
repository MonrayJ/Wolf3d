# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 13:29:20 by mjacobs           #+#    #+#              #
#    Updated: 2018/08/27 10:22:58 by mjacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf
FLAG = -Wall -Wextra -Werror
OPTION = -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit
SRC = main.c \
	  get_next_line/get_next_line.c \
	  draw.c \
	  readmap.c \
	  key_hook.c \
	  get_next_line/libft/libft.a \
	  ray_cast.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(OPTION) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all

