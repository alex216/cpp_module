NAME = harlFilter
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

.PHONEY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: fclean all

##########################################
.PHONY: test
test: all
	@echo "\n####test DEBUG"
	@./$(NAME) DEBUG
	@echo "\n####test INFO"
	@./$(NAME) INFO
	@echo "\n####test WARNING"
	@./$(NAME) WARNING
	@echo "\n####test ERROR"
	@./$(NAME) ERROR
	@echo "\n####test XXXX"
	@./$(NAME) XXXX
