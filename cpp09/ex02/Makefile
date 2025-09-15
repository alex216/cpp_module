NAME = PmergeMe
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all
all: $(NAME)

$(NAME): $(SRC) $(NAME).hpp
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: FLAGS += -g -O0 -fsanitize=address -fsanitize=undefined,integer
debug: fclean all test
	@python3 ./ford-jonson-tester/ford-johnson-tester.py

##########################################
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m  # No Color

.PHONY: test
test: all
	@echo "Testing PmergeMe with small sequence..."
	@./$(NAME) 3 5 9 7 4
	@echo ""
	@echo "Testing with negative number (should show Error)..."
	@./$(NAME) "-1" "2" 2>/dev/null && echo "$(RED)✗ Test failed$(NC)" || echo "$(GREEN)✓ Error handling works$(NC)"
	@echo ""
	@echo "Testing with single element..."
	@./$(NAME) 42
	@echo ""
	@echo "Testing with two elements..."
	@./$(NAME) 9 1
	@echo ""
	@echo "Testing with 8 elements..."
	@./$(NAME) 8 2 5 3 7 1 4 6
	@echo ""
	@echo "Testing with 10 elements..."
	@./$(NAME) 21 13 17 12 20 15 19 14 18 16
	@echo ""
	@echo "Testing with 21 elements..."
	@./$(NAME) 21 1 13 2 17 3 12 4 20 5 15 6 19 7 14 8 18 9 16 10 11
	@echo ""
	@echo "Testing various 3 elements..."
	@for i in {1..40}; do \
		./PmergeMe `shuf -i 1-100 -n 21 | tr '\n' ' '` | grep "com" ;\
	done


.PHONY: bigtest
bigtest: all
ifdef UNAME_S
ifeq ($(UNAME_S),Darwin)
	@echo "Testing with 100 random numbers on macOS..."
	@./$(NAME) `jot -r 100 1 10000 | tr '\n' ' '`
endif
else
	@echo "Testing with 100 random numbers on Linux..."
	@./$(NAME) `shuf -i 1-10000 -n 100 | tr "\n" " "`
endif

# S(10) = 22

# 21 13 17 12 20 15 19 14 18 16

# [13 21] [12 17] [15 20] [14 19] [16 18] Ans:5

# [17 21] [19 20] (18) Ans:5 + 2

# [20 21] Ans:5 + 2 + 1
# 19 17 18

# {19 20 21} Ans:5 + 2 + 1 + (0)
#       17 18

# {18 19 20 21} Ans:5 + 2 + 1 + (0 + 2)
#          17

# {17 18 19 20 21} Ans:5 + 2 + 1 + (0 + 2 + 2)
# 12 16 14 15 13

# {12 17 18 19 20 21} Ans:5 + 2 + 1 + (4) + (0)
#       16 14 15 13

# {12 14 17 18 19 20 21} Ans:5 + 2 + 1 + (4) + (0 + 2)
#          16    15 13

# {12 14 16 17 18 19 20 21} Ans:5 + 2 + 1 + (4) + (2 + 2)
#                   15 13

# {12 14 15 16 17 18 19 20 21} Ans:5 + 2 + 1 + (4) + (4) + (3)
#                      15

# {12 13 14 15 16 17 18 19 20 21} Ans:5 + 2 + 1 + (4) + (4) + (3 + 3) = 22
