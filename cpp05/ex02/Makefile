CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 28B_not_28C
SRCS = AForm.cpp  Bureaucrat.cpp  RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp  main.cpp

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