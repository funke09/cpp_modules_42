NAME = Zombie

SRC =  main.cpp Zombie.cpp randomChump.cpp newZombie.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

RM = rm -f

LIB = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

%.o : %.cpp $(LIB)
	$(CC) $(FLAGS) -o $@ -c $<

all : $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re:    fclean all

