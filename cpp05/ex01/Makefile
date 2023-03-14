NAME = Bureaucrat

SRC = main.cpp Bureaucrat.cpp Form.cpp


CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJCT = $(SRC:.cpp=.o)

$(NAME) : $(OBJCT)
	$(CXX) $(OBJCT) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp form.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJCT)

fclean : clean
	rm -rf $(NAME)

re : fclean all