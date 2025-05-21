NAME = ex00
SRC = *.cpp
HEADER = *.hpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

.PHONY: all
all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	@$(CXX) $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

.PHONY: re
re: clean all

##########################################
.PHONY: test
test: all
ifneq ($(shell uname), Darwin)
	@valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 -q ./$(NAME) && \
	echo "\n$(GREEN)test PASS, no memory leaks🚀$(NC)" || \
	echo "\n$(RED)test FAIL, memory leaks$(NC)"
else
	./$(NAME)
endif
