NAME = account
SRC = *.cpp
HEADERS = *.hpp
FILE = 19920104_091532.log

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors

.PHONY: all
all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	c++ $(CXXFLAGS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(NAME)

.PHONY: re
re: clean all

##########################################
.PHONY: ex
ex: all
	./$(NAME)

.PHONY: testall
testall: $(SRC) $(HEADERS)
	@c++ $(SRC) -o $(NAME)

.PHONY: diff
diff: testall
	@./$(NAME) > result.txt
	@COMPARELINE=$$(./$(NAME) | wc -l | bc); \
	head -n $$COMPARELINE $(FILE) | diff result.txt -
	@if [ $$? -eq 0 ]; then \
		echo "test PASS"; \
	fi
