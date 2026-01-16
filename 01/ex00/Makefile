
CC = c++
CFLAGS = -Wall -Werror -Wextra
SRC = Zombie.cpp newzombie.cpp randomchump.cpp main.cpp
NAME = Zombie
OBJ = $(SRC:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all