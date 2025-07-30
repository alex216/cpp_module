NAME = RPN
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all
all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

##########################################
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m  # No Color

.PHONY: test
test: all
	@echo "Testing RPN calculator..."
	@echo "Test 1: '8 9 * 9 - 9 - 9 - 4 - 1 +' should equal 42"
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +" && echo "$(GREEN)✓ Test 1 passed$(NC)" || echo "$(RED)✗ Test 1 failed$(NC)"
	@echo "Test 2: '7 7 * 7 -' should equal 42"
	@./$(NAME) "7 7 * 7 -" && echo "$(GREEN)✓ Test 2 passed$(NC)" || echo "$(RED)✗ Test 2 failed$(NC)"
	@echo "Test 3: '1 2 * 2 / 2 * 2 4 - +' should equal 0"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +" && echo "$(GREEN)✓ Test 3 passed$(NC)" || echo "$(RED)✗ Test 3 failed$(NC)"
	@echo "Test 4: '(1 + 1)' should show Error"
	@./$(NAME) "(1 + 1)" 2>/dev/null && echo "$(RED)✗ Test 4 failed$(NC)" || echo "$(GREEN)✓ Test 4 passed$(NC)"