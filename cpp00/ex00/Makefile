# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 23:51:28 by zcherrad          #+#    #+#              #
#    Updated: 2023/02/14 23:51:29 by zcherrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MegaPhone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = MegaPhone.hpp
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