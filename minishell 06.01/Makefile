NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
      src/prompt.c \
      src/executor.c \
      src/parser.c \
      src/executor_2.c \
      src/command_completion.c

OBJ = $(SRC:.c=.o)
INC = -Iinc
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
