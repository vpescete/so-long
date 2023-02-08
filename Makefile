NAME = so_long

SRC = window/ft_close.c window/ft_preload.c window/main.c \
		map/ft_check_map.c map/ft_load_images_on_map.c map/ft_load_map.c window/ft_win.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		game/ft_check_error.c game/ft_load_sprites.c \
		control_btt/ft_hooks.c control_btt/ft_key_control.c \
		animations/ft_color.c animations/ft_update.c animations/ft_winscreen.c \
		enemy/ft_enemy_behaviour.c enemy/ft_load_enemy.c \
		mini_libft/ft_function.c mini_libft/ft_itoa.c \

OBJ = $(SRC.c=.o)

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit ft_printf/libftprintf.a
MINILIBX := minilibx/
FTPRINTF := ft_printf/

FLAG = -Wall -Werror -Wextra
CC = gcc

all : 
		make -C $(MINILIBX)
		make -C $(FTPRINTF)
	$(CC) $(CFLAGS) $(SRC) $(LIBRARY) -o $(NAME) -lz -g

clean: 
	make clean -C $(MINILIBX)
	make fclean -C $(FTPRINTF)
	rm -f $(OBJ)
	
fclean:	clean
	rm -f $(NAME)

re:	fclean all clean

.PHONY: all clean fclean re
