CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

CFILE = main.cpp  newZombie.cpp  randomChump.cpp  Zombie.cpp

NAME = ZMBBY

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME):
	@printf "\n"
	@printf "$(GREEN)            ___ ___        ___    _____    _     _      ___ ___   \n$(RESET)"
	@printf "$(GREEN) ___ _ _   |   |   |   ___|  _|  |    _| _| |_ _| |_   |   |_  |  \n$(RESET)"
	@printf "$(GREEN)| -_|_'_|  | | | | |  | . |  _|  |   |_ |_   _|_   _|  | | |_| |_ \n$(RESET)"
	@printf "$(GREEN)|___|_,_|  |___|___|  |___|_|    |_____|  |_|   |_|    |___|_____|\n$(RESET)"
	@printf "$(GREEN)                                                                  \n$(RESET)"
	@printf "\n"
	$(CC) $(CFLAGS) $(CFILE) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re