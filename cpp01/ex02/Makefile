CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

NAME = this_is_brain

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re