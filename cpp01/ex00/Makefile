# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 22:10:37 by zcherrad          #+#    #+#              #
#    Updated: 2023/02/20 18:43:58 by zcherrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

SRC =  main.cpp Zombie.cpp randomChump.cpp newZombie.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

LIB = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ) $(LIB)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

%.o : %.cpp $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

all : $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re:    fclean all

