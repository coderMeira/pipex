
CFLAGS = -Wall -Werror -Wextra -g

NAME = pipex

LIBFT_DIR = ../lib/libft/src
LIBFT_EXEC = ../lib/libft/bin/libft.a

SRCS = pipex.c utils.c search_path.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_EXEC) $(OBJS)
		gcc $(CFLAGS) $(LIBFT_EXEC) $(OBJS) -o $(NAME) && mv $(NAME) ../bin
		@echo "Ready to use!"

$(LIBFT_EXEC):
		@echo "Compiling libft"
		cd $(LIBFT_DIR) && make

clean:
	rm -rf $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean:
	rm -rf $(OBJS) ../bin/$(NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean all
