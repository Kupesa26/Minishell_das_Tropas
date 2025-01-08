NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	src/command_completion.c \
	src/executor.c \
	src/executor_2.c \
	src/main.c \
	src/parser.c  \
	src/prompt.c \
	src/smart_split.c

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
INC = -Iinc
LIBFT = libft/libft.a

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
