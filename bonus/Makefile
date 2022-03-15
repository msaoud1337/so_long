NAME  =  so_long_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = so_long_bonus.c reading_map.c checking_map.c ./get_next_line/get_next_line.c\
	./get_next_line/get_next_line_utils.c graph.c ft_up.c\
	ft_putnbr.c ft_itoa.c ft_free.c enemy.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(SRCS) $(OBJ) game_bonus.h
	$(CC) $(FLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC)  $(FLAGS) -c $<

clean : 
	rm -rf $(OBJ) get_next_line.o get_next_line_utils.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all
