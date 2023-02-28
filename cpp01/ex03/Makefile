# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 22:11:25 by zcherrad          #+#    #+#              #
#    Updated: 2023/02/19 22:11:27 by zcherrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC =  main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

RM = rm -f

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

all : $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re:    fclean all