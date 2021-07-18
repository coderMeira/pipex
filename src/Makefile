
CFLAGS = -Wall -Werror -Wextra -g

NAME = pipex

SRCS = pipex.c ../lib/libft/src/libft.a 

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(FLAGS) -o $(NAME) && mv $(NAME) ../bin

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all
