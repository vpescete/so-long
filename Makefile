NAME = so_long

SRC = window/*.c \
		map/*c \
		get_next_line/*.c \
		game/*.c \
		control_btt/*.c \

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
