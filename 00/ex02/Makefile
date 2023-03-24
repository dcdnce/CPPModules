# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforesti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 14:40:58 by pforesti          #+#    #+#              #
#    Updated: 2022/04/16 15:02:17 by pforesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02

%o	:	%.cpp
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
