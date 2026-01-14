CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Animal.cpp  Cat.cpp  Dog.cpp  main.cpp WrongAnimal.cpp  WrongCat.cpp Brain.cpp
DEP = Animal.hpp  Cat.hpp  Dog.hpp WrongAnimal.hpp  WrongCat.hpp 
OBJ = $(SRC:.cpp=.o)
NAME = main

all : $(NAME)

%.o: %.cpp $(DEP)
	$(CXX) -c $(CPPFLAGS) $< -o $@

$(NAME): $(OBJ) 
	$(CXX) $^ -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:
	all clean fclean re

.SECONDARY:$(OBJ)