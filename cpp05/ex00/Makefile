# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 03:10:09 by zcherrad          #+#    #+#              #
#    Updated: 2023/03/24 03:10:10 by zcherrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

SRC = main.cpp Bureaucrat.cpp 


CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJCT = $(SRC:.cpp=.o)

$(NAME) : $(OBJCT)
	$(CXX) $(OBJCT) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJCT)

fclean : clean
	rm -rf $(NAME)

re : fclean all