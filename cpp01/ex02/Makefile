NAME = a.out
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
	@./$(NAME)
