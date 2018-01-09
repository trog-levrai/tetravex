SRC=src/main.cc src/grid.cc
CPPFLAGS=-g -std=c++14 -Wall -Wextra -Werror -Weffc++
BIN=tetravex
CPP=g++

all:
	$(CPP) $(CPPFLAGS) $(SRC) -o $(BIN)

check: all
	./$(BIN) 3

clean:
	$(RM) $(BIN)

.PHONY: clean
