CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

NAME = fighting_humans

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re