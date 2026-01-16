CC = c++
CFLAGS = -Wall -Werror -Wextra
SRC = Contact.cpp PhoneBook.cpp printable.cpp main.cpp
NAME = phone
OBJ = $(SRC:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.o : .cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all