NAME = account
SRC = *.cpp
HEADERS = *.hpp
FILE = 19920104_091532.log
GREEN = \033[0;32m
NC = \033[0m  # No Color

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors

.PHONY: all
all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	c++ $(CXXFLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(NAME)

.PHONE: fclean
fclean: clean
	rm -f result.txt $(FILE)

.PHONY: re
re: clean all

##########################################
.PHONY: ex
ex: all
	./$(NAME)

.PHONY: test
test: all

	@if [ ! -f $(FILE) ]; then \
		curl -s https://cdn.intra.42.fr/document/document/28346/19920104_091532.log -o $(FILE); \
	fi
	./$(NAME) > result.txt

	diff $(FILE) result.txt 

	@if [ $$? -eq 0 ]; then \
		echo "$(GREEN)test PASS$(NC)"; \
	fi
