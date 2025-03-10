
NAME = megaphone

SRC = ./megaphone.cpp

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(NAME): $(SRC)
	@echo "\n\033[0;32mMAKE IT LOUD!!\033[0m\n"
	@$(CC) $(FLAGS) -o $@ $^

clean:

fclean: clean
	@rm -f $(NAME)
	@echo "\n\033[0;31mAll is gone\033[0m\n"

re: fclean all

.PHONY: all clean re fclean
