NAME = phonebook
SRC = *.cpp
HEADERS = *.hpp

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
.PHONY: debug
mr: all
	./$(NAME)

.PHONY: test
test: all
	@rm -rf go.mod
	@go mod init hoge
	@cd test && go test -v
