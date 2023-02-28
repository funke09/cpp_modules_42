NAME = Fixed

SRC =  main.cpp Fixed.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98


LIB = Fixed.hpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ) $(LIB)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

%.o : %.cpp $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:    fclean all