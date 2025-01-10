NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

.PHONY: all
all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

.PHONY: re
re: clean all

.PHONY: test
test: all
	@echo "--------------------------------------------"
	./$(NAME) "shhhhh... I think the students are asleep..."
	@echo "--------------------------------------------"
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@echo "--------------------------------------------"
	./$(NAME) "Hello World!"
	@echo "--------------------------------------------"
	./$(NAME)
