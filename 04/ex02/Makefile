#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforesti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 11:45:18 by pforesti          #+#    #+#              #
#    Updated: 2022/11/20 18:48:51 by pforesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98


NAME = ex02

%.o : $.cpp
	$(CPPC) $(CPPFLAGS) -c $< -o $@ 
######################################################################
######################################################################

$(NAME) : $(OBJS)
	$(CPPC) -o $@ $^ -g

all :$(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
