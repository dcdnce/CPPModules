# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:49:25 by pforesti          #+#    #+#              #
#    Updated: 2023/04/12 11:32:12 by pforesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.cpp \
		RPN.cpp

OBJS = $(SRCS:.cpp=.o)

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PmergeMe

%.o : %.cpp 
	$(C) $(CFLAGS) -c $< -o $@

##############################################
##############################################

$(NAME) : $(OBJS)
	$(C) -o $@ $^

all : $(NAME)

clean :
	rm -rf $(OBJS)
	
fclean : clean
	rm -rf $(NAME)
	
re : fclean all

.PHONY : all clean fclean re