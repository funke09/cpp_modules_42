# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 23:51:11 by zcherrad          #+#    #+#              #
#    Updated: 2023/02/15 19:08:34 by zcherrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
SRC = main.cpp Contact.cpp PhoneBook.cpp 
OBJ = $(SRC:.cpp=.o)
CC = c++
HEADER = Contact.hpp PhoneBook.hpp
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all:$(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
