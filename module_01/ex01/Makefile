
NAME = zombie

SRC_DIR = sources

SRC = $(SRC_DIR)/main.cpp\
	$(SRC_DIR)/Zombie.cpp\

OBJ_DIR = objects

OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

COMP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(COMP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(COMP) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n\033[0;32mTime to make some calls!\033[0m\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "\n\033[0;31mAll is gone\033[0m\n"

re: fclean all

.PHONY: all clean re fclean
