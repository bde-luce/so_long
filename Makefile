# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 17:33:19 by bde-luce          #+#    #+#              #
#    Updated: 2024/11/21 17:33:19 by bde-luce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
MLX_DIR = mlx_linux

INCLUDES = -I/usr/include -I$(INC_DIR) -I$(LIBFT_DIR)/inc -I$(FT_PRINTF_DIR)/inc -I$(GNL_DIR)/inc -I$(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

SRCS =	map_convert.c map_validity.c map_validity2.c map_winnability.c \
		create_close_window.c key_hook.c so_long.c bonus.c

GNL_SRCS =	get_next_line.c get_next_line_utils.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
GNL_OBJS = $(addprefix $(OBJ_DIR)/get_next_line/, $(GNL_SRCS:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx.a

MSG_BUILD = @echo "🔨 Building $(NAME)..."
MSG_DONE = @echo "✅ Done"
MSG_CLEAN = @echo "🧹 Cleaning object files..."
MSG_FCLEAN = @echo "🧼 Removing executable..."
MSG_RE = @echo "🔁 Rebuilding..."

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIB)
	$(MSG_BUILD)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS)
	$(MSG_DONE)

$(LIBFT):
	@echo "📚 Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@echo "🖨️ Building ft_printf..."
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX_LIB):
	@echo "🖼️ Building mlx_linux..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "✅ mlx_linux built"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🧱 Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/get_next_line/%.o: $(GNL_DIR)/src/%.c
	@mkdir -p $(dir $@)
	@echo "🧱 Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MSG_CLEAN)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(FT_PRINTF_DIR)
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1
	@rm -rf $(OBJ_DIR)
	$(MSG_DONE)

fclean: clean
	$(MSG_FCLEAN)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(FT_PRINTF_DIR)
	@rm -f $(NAME)
	$(MSG_DONE)

re:
	$(MSG_RE)
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re