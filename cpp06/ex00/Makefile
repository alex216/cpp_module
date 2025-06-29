GREEN = \033[0;32m
NC = \033[0m  # No Color

NAME = convert
SRC = *.cpp
HEADER = *.hpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all
all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	@rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: clean all

##########################################
.PHONY: test
test: all
	@make test_basic
	@make test_char
	@make test_int
	@make test_float
	@make test_double

.PHONEY: test_basic
test_basic: all
	@printf "$(GREEN)### basic test ###$(NC)\n"
	./$(NAME)
	@printf "\n"

	./$(NAME) 0
	@printf "\n"

	./$(NAME) nan
	@printf "\n"

	./$(NAME) 42.0f
	@printf "\n"

.PHONY: test_char
test_char: all
	@printf "$(GREEN)### char check ###$(NC)\n"
	./$(NAME) 42 char
	@printf "\n"

	./$(NAME) x char
	@printf "\n"

	./$(NAME) 0 char
	@printf "\n"

	./$(NAME) "hello" char
	@printf "\n"

.PHONY: test_int
test_int: all
	@printf "$(GREEN)### int check ###$(NC)\n"
	./$(NAME) 0 int
	@printf "\n"

	./$(NAME) 42 int
	@printf "\n"

	./$(NAME) -42 int
	@printf "\n"

	./$(NAME) x int
	@printf "\n"

	./$(NAME) 42hello int
	@printf "\n"

	./$(NAME) 2147483647 int
	@printf "\n"

	./$(NAME) -2147483648 int
	@printf "\n"

	./$(NAME) 2147483648 int
	@printf "\n"
	
	./$(NAME) -2147483649 int
	@printf "\n"

.PHONY: test_float
test_float: all
	@printf "$(GREEN)### float check ###$(NC)\n"
	./$(NAME) 42.0 float
	@printf "\n"

	./$(NAME) 42.12342 float
	@printf "\n"

	./$(NAME) 42.12342 float
	@printf "\n"

	./$(NAME) 42.00042f42 float
	@printf "\n"

	./$(NAME) 422222222222222222222222222222222222222.22222f float
	@printf "\n"

	./$(NAME) -422222222222222222222222222222222222222.22222f float
	@printf "\n"

.PHONY: test_double
test_double: all
	@printf "$(GREEN)### double check ###$(NC)\n"
	./$(NAME) 42.0 double
	@printf "\n"

	./$(NAME) 42.12342 double
	@printf "\n"

	./$(NAME) 42.12342 double
	@printf "\n"

	./$(NAME) 42.00042f42 double
	@printf "\n"

	./$(NAME) 422222222222222222222222222222222222222.22222f double
	@printf "\n"

	./$(NAME) -422222222222222222222222222222222222222.22222f double
	@printf "\n"

	./$(NAME) 99999999999999999999999333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0 double
	@printf "\n"

	./$(NAME) -99999999999999999999999333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0 double
	@printf "\n"
