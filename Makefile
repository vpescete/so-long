NAME = so_long

SRC = window/*.c \
		map/*c \
		get_next_line/*.c \

OBJ = $(SRC.c=.o)

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

FLAG = -Wall -Werror -Wextra
CC = gcc

all : 
		make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SRC) $(LIBRARY) -o $(NAME) -lz -g

clean: 
	rm -f $(OBJ) $(BOBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all clean

.PHONY: all clean fclean re
