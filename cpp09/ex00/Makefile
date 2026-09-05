CXX = c++
CPPFLAGS = -Wall -Wextra -std=c++98 -g -Werror
SRC =  main.cpp BitcoinExchange.cpp
DEP = BitcoinExchange.hpp
OBJ = $(SRC:.cpp=.o)
NAME = btc

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