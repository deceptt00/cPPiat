
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = ClapTrap.cpp ScavTrap.cpp main.cpp
NAME = ScavTrap
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