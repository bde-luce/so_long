# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:45:04 by bde-luce          #+#    #+#              #
#    Updated: 2026/03/23 12:40:29 by bde-luce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

INCLUDES = -I$(INC_DIR)

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))

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

bonus: $(OBJS) $(BONUS_OBJS)
	$(MSG_BUILD)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	$(MSG_DONE)

.PHONY: all clean fclean re bonus