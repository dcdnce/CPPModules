#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pforesti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 11:45:18 by pforesti          #+#    #+#              #
#    Updated: 2022/12/07 16:50:07 by pforesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)

CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex03

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
