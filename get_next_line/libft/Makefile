# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 08:05:09 by mjacobs           #+#    #+#              #
#    Updated: 2018/08/23 13:45:49 by mjacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH_C = ./
HEADER = libft.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC1 = $(PATH_C)ft_memset.c \
	   $(PATH_C)ft_bzero.c \
	   $(PATH_C)ft_memcpy.c \
	   $(PATH_C)ft_memccpy.c \
	   $(PATH_C)ft_memmove.c \
	   $(PATH_C)ft_memchr.c \
	   $(PATH_C)ft_memcmp.c \
	   $(PATH_C)ft_strlen.c \
	   $(PATH_C)ft_strdup.c \
	   $(PATH_C)ft_strcpy.c \
	   $(PATH_C)ft_strncpy.c \
	   $(PATH_C)ft_strcat.c \
	   $(PATH_C)ft_strncat.c \
	   $(PATH_C)ft_strlcat.c \
	   $(PATH_C)ft_strchr.c \
	   $(PATH_C)ft_strrchr.c \
	   $(PATH_C)ft_strstr.c \
	   $(PATH_C)ft_strnstr.c \
	   $(PATH_C)ft_strcmp.c \
	   $(PATH_C)ft_strncmp.c \
	   $(PATH_C)ft_atoi.c \
	   $(PATH_C)ft_isalpha.c \
	   $(PATH_C)ft_isdigit.c \
	   $(PATH_C)ft_isalnum.c \
	   $(PATH_C)ft_isascii.c \
	   $(PATH_C)ft_isprint.c \
	   $(PATH_C)ft_toupper.c \
	   $(PATH_C)ft_tolower.c \
	   $(PATH_C)ft_memalloc.c \
	   $(PATH_C)ft_striter.c \

SRC2 = $(PATH_C)ft_memalloc.c \
	   $(PATH_C)ft_memdel.c \
	   $(PATH_C)ft_strnew.c \
	   $(PATH_C)ft_strdel.c \
	   $(PATH_C)ft_strclr.c \
	   $(PATH_C)ft_striter.c \
	   $(PATH_C)ft_striteri.c \
	   $(PATH_C)ft_strmap.c \
	   $(PATH_C)ft_strmapi.c \
	   $(PATH_C)ft_strequ.c \
	   $(PATH_C)ft_strnequ.c \
	   $(PATH_C)ft_strsub.c \
	   $(PATH_C)ft_strjoin.c \
	   $(PATH_C)ft_strtrim.c \
	   $(PATH_C)ft_strsplit.c \
	   $(PATH_C)ft_itoa.c \
	   $(PATH_C)ft_putchar.c \
	   $(PATH_C)ft_putstr.c \
	   $(PATH_C)ft_putendl.c \
	   $(PATH_C)ft_putnbr.c \
	   $(PATH_C)ft_putchar_fd.c \
	   $(PATH_C)ft_putstr_fd.c \
	   $(PATH_C)ft_putendl_fd.c \
	   $(PATH_C)ft_putnbr_fd.c \
	   $(PATH_C)ft_whitespace.c \
	   $(PATH_C)ft_strchlen.c \
	   $(PATH_C)ft_word_cnt.c \

OBJECT = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC1) $(SRC2)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
