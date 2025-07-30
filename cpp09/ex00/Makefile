NAME = btc
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
NC = \033[0m  # No Color

.PHONY: test
test: all
ifneq ($(shell uname), Darwin)
	@valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 -q "./$(NAME) input.csv" > tmp_result.txt 2> tmp_result_err.txt && \
	echo "\n$(GREEN)test PASS, no memory leaks🚀$(NC)" || \
	echo "\n$(RED)test FAIL, memory leaks$(NC)"
else
	./$(NAME) input.csv > tmp_result.txt 2> tmp_result_err.txt
endif

	diff result.txt tmp_result.txt 

	@if [ $$? -eq 0 ]; then \
		echo "$(GREEN)stdout test PASS$(NC)"; \
	fi

	diff result_err.txt tmp_result_err.txt 

	@if [ $$? -eq 0 ]; then \
		echo "$(GREEN)stderr test PASS$(NC)"; \
	fi

	@rm -f tmp_result.txt tmp_result_err.txt
