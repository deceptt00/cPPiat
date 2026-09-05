CXX = c++
CPPFLAGS = -Wall -Wextra -std=c++98 -g -Werror
SRC =  Span.cpp main.cpp
DEP = Span.hpp
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