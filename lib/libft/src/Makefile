# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 20:38:48 by fmeira            #+#    #+#              #
#    Updated: 2021/07/23 17:50:52 by fmeira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

NAME = libft.a
HEADER = ../inc/libft.h
SRC = ${wildcard ft_*.c}
OBJ = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	ar -rs ${NAME} ${OBJ} && mv $(NAME) ../bin

%.o: %.c
	gcc ${FLAGS} -c -o $@ $<

all: ${NAME}

bonus: ${NAME}

clean:
	rm -f ${OBJ}

.PHONY: clean
fclean: clean
	rm -f ../bin/${NAME}

re: fclean all
