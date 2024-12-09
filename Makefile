# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupesa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:11:45 by akupesa           #+#    #+#              #
#    Updated: 2024/11/19 11:12:46 by akupesa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj
INCDIR = include

SRC =	builtin_handlers.c \
	env_manager.c \
	executor.c \
	main.c \
	parser.c \
	redirection.c \
	signal_handler.c \
	utils.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

/readline
LIBS = -lreadline

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compilation in process..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Making directory and .obj..."
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	@echo "Cleaning .obj..."
	$(RM) -r $(OBJDIR)

fclean: clean
	@echo "Cleaning all..."
	$(RM) $(NAME)

re: fclean all

//Flags para debug(NÃO ESQUECE DE TIRAR, MENDES)
debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
