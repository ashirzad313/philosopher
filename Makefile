CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

SRC = src/main.c src/utils.c src/init.c src/thread.c src/helper.c src/manager.c src/time.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

