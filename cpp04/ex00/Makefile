NAME = Animal

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:.cpp=.o)
HEDER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
FLAGS = -Wall -Wextra -Werror

CC = c++

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

%.o: %.cpp $(HEDER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all