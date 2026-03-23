# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 16:22:33 by bde-luce          #+#    #+#              #
#    Updated: 2026/03/23 12:41:09 by bde-luce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

INCLUDES = -I$(INC_DIR)

SRCS =	ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c ft_putnbrhex.c \
		ft_num_len_ptr.c ft_num_len_nbr.c ft_check_type.c ft_printf.c \
		ft_putunbr.c ft_num_len_unbr.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

MSG_BUILD = @echo "📚 Building $(NAME)..."
MSG_DONE = @echo "✅ Done"
MSG_CLEAN = @echo "🧹 Cleaning object files..."
MSG_FCLEAN = @echo "🧼 Removing library..."
MSG_RE = @echo "🔁 Rebuilding..."

all: $(NAME)

$(NAME): $(OBJS)
	$(MSG_BUILD)
	@ar rcs $(NAME) $(OBJS)
	$(MSG_DONE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "🧱 Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MSG_CLEAN)
	@rm -rf $(OBJ_DIR)
	$(MSG_DONE)

fclean: clean
	$(MSG_FCLEAN)
	@rm -f $(NAME)
	$(MSG_DONE)

re:
	$(MSG_RE)
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re