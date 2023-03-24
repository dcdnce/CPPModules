# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforesti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 14:40:58 by pforesti          #+#    #+#              #
#    Updated: 2022/03/05 12:15:47 by pforesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

%.o	:	%.cpp
		$(CPPC) $(CPPFLAGS) -c $< -o $@

#######################################################################################
#######################################################################################
all:	$(NAME)

$(NAME):	$(OBJS)
	$(CPPC) -o $@ $^ 

debug:	$(OBJS)
	$(CPPC) -g -o $@ $^ 

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re 
