# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:49:25 by pforesti          #+#    #+#              #
#    Updated: 2023/01/19 15:28:47 by pforesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex01

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