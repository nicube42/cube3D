NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a
SRC = main.c \
		init/init.c \
		init/init2.c \
		raycasting/raycasting.c \
		raycasting/raycasting2.c \
		hooks/hooks.c \
		hooks/hooks2.c \
		hooks/hooks3.c \
		render/render.c \
		render/minimap.c \
		render/gun.c \
		parsing/00_parsing.c \
		parsing/02_parsing_utils.c \
		parsing/03_open_cub.c \
		parsing/11_get_texture.c \
		parsing/12_get_color.c \
		parsing/20_map_generate.c \
		parsing/21_add_line.c \
		parsing/22_adjust_map.c \
		parsing/23_check_map.c

DIRS	= raycasting/ hooks/ render/ init/ parsing/

OBJ_DIR = $(addprefix obj/, $(DIRS))
OBJS = $(addprefix obj/, $(SRC:.c=.o))
SRCS = $(addprefix src/, $(SRC))

LIBFT = libft.a

all: create_dirs $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

create_dirs:
	mkdir -p obj/
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx/
	$(CC)  $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o $(NAME) -Llibft/ -lftprintf -lz

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $< -I ./includes

clean:
	rm -rf obj/
	$(MAKE) -C libft/ clean

fclean:
	rm -rf obj/
	rm -f $(NAME)
	$(MAKE) -C ./mlx/ clean
	$(MAKE) -C libft/ fclean

re: fclean all

fast:
	$(MAKE) -j -C ./libft
	$(MAKE) -C ./mlx/
	$(MAKE) -j$(nproc)

.PHONY: all create_dirs clean fclean re fast

