NAME = test
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = #whatever.hpp
FLAGS = c++ -Wall -Wextra -Werror -std=c++98 

all: $(NAME)
	  $(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp $(HEADER)
	  $(FLAGS) -c $< -o $@

clean:
	  rm -f $(OBJ)

fclean: clean
	  rm -f $(NAME)

re: fclean all