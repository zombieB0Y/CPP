CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = world_on_fire
SRCS = Animal.cpp  Cat.cpp  Dog.cpp  main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
 
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re