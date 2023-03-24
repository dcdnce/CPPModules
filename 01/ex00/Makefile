SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

CPPC = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

NAME = ex00

%.o : %.cpp
	$(CPPC) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPC) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
