# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 18:28:13 by pedessan          #+#    #+#              #
#    Updated: 2025/05/22 13:02:42 by pdessant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

UNAME = $(shell uname -s)

CC = cc

LIBFT = ./libft/libft.a

#SL_HEADER_FILE = $(INC_DIR)/fdf.h
SL_HEADER_FILE = -I.

ifeq ($(UNAME),Darwin)
########  MACOS ########
  MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
else
########  LINUX ########
  MINILIBX = MiniLibX/libmlx.a -lm -lX11 -lXext 
 
endif

CFLAGS = -Wall -Wextra -Werror -g

SRC =	\
		color_fractal.c					\
		parsing_prova.c					\
		parsing_args.c					\
		parsing_print_instructions.c	\
		fractol_init_values.c			\
		fractals_setup.c				\
		utils_my_pixel_put.c			\
		draw_fractal.c					\
		fractal_mandelbrot.c			\
		fractal_julia.c					\
		math_newton.c					\
		fractal_newton.c				\
		fractal_render.c				\
		event_mouse_hook.c				\
		event_mlx_hook_event.c			\
		win_close_window.c				\
		main.c

GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NO_COLOR = \033[0m

all: $(LIBFT) MiniLibX/libmlx.a $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINILIBX) -o $(NAME) 
	@echo "$(GREEN)programma compilato con successo $(NO_COLOR)"

clean:
	@make clean -C libft
#	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	rm -rf MiniLibX
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

MiniLibX/libmlx.a:
	git clone https://github.com/42Paris/minilibx-linux.git MiniLibX
	@make -C MiniLibX > /dev/null 2>&1

#	@make -C MiniLibX 2> /dev/null
#	make -C MiniLibX
#	make -C minilibx-linux

