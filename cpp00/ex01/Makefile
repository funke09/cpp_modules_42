NAME = phoneBook
SRC = phoneBook.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = phone.hpp
FLAGS = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)
	$(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all