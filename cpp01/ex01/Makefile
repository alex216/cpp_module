NAME = Zombie
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m  # No Color

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

.PHONY: all
all: $(NAME)

$(NAME): $(SRC)
	@$(CXX) $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	@rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: fclean all

##########################################
.PHONY: test
test: all
ifneq ($(shell uname), Darwin)
	@valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 -q ./$(NAME) && \
	echo "\n$(GREEN)test PASS, no memory leaks🚀$(NC)" || \
	echo "\n$(RED)test FAIL, memory leaks$(NC)"
else
	@./$(NAME)
endif
