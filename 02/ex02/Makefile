# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforesti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 11:45:18 by pforesti          #+#    #+#              #
#    Updated: 2022/09/15 08:11:24 by pforesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02

%.o : $.cpp
	$(CPPC) $(CPPFLAGS) -c $< -o $@

######################################################################
######################################################################

$(NAME) : $(OBJS)
	$(CPPC) -o $@ $^

all :$(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
