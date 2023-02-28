# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 22:10:53 by zcherrad          #+#    #+#              #
#    Updated: 2023/02/19 22:10:55 by zcherrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

SRC =  main.cpp Zombie.cpp zombieHorde.cpp

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