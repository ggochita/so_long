NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iincludes -g
SRC_DIR := src
MINILIBX := lib/minilibx-linux
LIBPRINTF := lib/ft_printf
LIBRARY := -L$(LIBPRINTF) -lftprintf -L$(MINILIBX) -lmlx -lX11 -lXext -lm
SRC := ./src/check_ber.c ./src/check_map.c ./src/creat_map.c ./src/error_text.c ./src/handler.c \
       ./src/main.c ./src/map_init.c ./src/moves.c ./src/path_algo_utils.c ./src/path_algo.c \
       ./src/render.c ./src/utils.c ./lib/get_next_line/get_next_line.c ./src/window_init.c \
       ./lib/get_next_line/get_next_line_utils.c ./src/player_init.c

OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MINILIBX)
	@make -C $(LIBPRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
	echo -e "\033[32m\n        FINISH\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(MINILIBX)
	@make clean -C $(LIBPRINTF)
	@rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*/*.o

fclean: clean
	@make clean -C $(MINILIBX)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
