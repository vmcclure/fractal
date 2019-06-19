NAME = fractal
SRC = main.c ft_thread.c complex_math.c mkey.c tkey.c input.c drow.c
LFT_PATH = libft/ft_atoi.c libft/ft_memalloc.c libft/ft_putstr.c \
libft/ft_bzero.c libft/ft_strjoin.c libft/ft_putchar.c libft/ft_strcat.c \
libft/ft_strcpy.c libft/ft_strlen.c
OUT = *.o
INC = fractal.h
MINI = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror -Ofast -std=c99 -lpthread  
all:$(SRC)
	gcc  $(FLAGS) -o $(NAME) -I $(INC) $(SRC) $(MINI) $(LFT_PATH)
clean:
	rm -f $(OUT)
fclean:	clean
	rm -f $(NAME)
re: 	fclean all