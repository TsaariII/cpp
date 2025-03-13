
NAME = brain

SRC = ./main.cpp

COMP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(NAME): $(SRC)
	@$(COMP) $(CFLAGS) -o $@ $^
	@echo "\n\033[0;32mGimme some brain\033[0m\n"

clean:

fclean: clean
	@rm -f $(NAME)
	@echo "\n\033[0;31mAll is gone\033[0m\n"

re: fclean all

.PHONY: all clean re fclean
