NAME = Zombie
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

.PHONY: all
all: $(NAME)

$(NAME): $(SRC)
	@$(CXX) $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	@rm -f $(OBJ)

.PHONY: re
re: clean all

##########################################
.PHONY: test
test: all
ifneq ($(shell uname), Darwin)
	@valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME)
else
	@./$(NAME)
endif
