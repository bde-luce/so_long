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

NAME = so_long

OBJ_DIR = obj

SRCS = map_convert.c map_validity.c map_validity2.c map_winnability.c \
	create_close_window.c key_hook.c so_long.c bonus.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I/usr/include -I$(LIBFT_DIR) -I$(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re