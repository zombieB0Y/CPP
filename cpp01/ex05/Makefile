CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS = Harl.cpp  main.cpp

NAME = harl

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re