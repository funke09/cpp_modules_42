NAME = a.out

SRC = main.cpp Fixed.cpp Operator.cpp

HEDERE = Fixed.hpp

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -std=c++98

OBJCT = $(SRC:.cpp=.o)

$(NAME): $(OBJCT)
		$(CC) $(OBJCT) $(CFLAGS) -o $(NAME)
%.o:%.cpp $(HEDERE)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJCT)

fclean : clean
	rm -rf $(NAME)

re : fclean all