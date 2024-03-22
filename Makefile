# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darkwater <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 23:52:29 by darkwater         #+#    #+#              #
#    Updated: 2024/03/21 16:23:49 by darkwater        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC				= main.c		\
				utils.c			\
				push_swap.c

SRCPRE			= $(addprefix $(SRCDIR), $(SRC))

SRCDIR			= ./src/

OBJS			= $(SRCPRE:.c=.o)

OBJ_OUTPUT		= .output

HEADER			= ./includes/

LIBFT_NAME		= libft.a

LIBFT_DIR		= ./libft/

LIBFT_PRE		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -Wpedantic -g

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Colours  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

RED				= \033[0;31m

GREEN			= \033[0;32m

NC				= \033[0m

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Messages ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

BEGIN_COMP		= echo "\n ~ ~ ~ $(GREEN)Compiling Objects$(NC) ~ ~ ~\n"

PROGRAM_COMP	= echo "\n ~ ~ ~ $(GREEN)Compiling Program$(NC) ~ ~ ~\n"

CLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Cleaning all object files$(NC) ~ ~ ~\n"

FCLEAN_MSG		= echo "\n ~ ~ ~ $(RED)Removing Programs$(NC) ~ ~ ~\n"

# ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Rules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ #

all: $(NAME)

$(NAME): $(LIBFT_PRE) $(OBJ_OUTPUT) $(OBJS)
	@$(PROGRAM_COMP)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_OUTPUT):
	@$(BEGIN_COMP)
	@touch .output

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

$(LIBFT_PRE):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(CLEAN_MSG)
	rm -f $(OBJ_OUTPUT) $(OBJS)

fclean: clean
	@$(FCLEAN_MSG)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
