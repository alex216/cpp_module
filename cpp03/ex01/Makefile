NAME = main
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
.PHONY: debug
debug: FLAGS += -DDEBUG
debug: re

.PHONY: run_with_valgrind
run_with_valgrind:
ifneq ($(shell uname), Darwin)
	@valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 -q ./$(NAME) && \
	echo "\n$(GREEN)PASS, no memory leaks🚀$(NC)" || \
	echo "\n$(RED)FAIL, memory leaks$(NC)"
else
	./$(NAME)
endif

.PHONY: debugtest
debugtest: debug run_with_valgrind

.PHONY: test
test: re run_with_valgrind
