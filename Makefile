SRC=src/main.cc
CPPFLAGS=-g -std=c++14 -Wall -Wextra -Werror -Weffc++
BIN=tetravex
CPP=g++

all:
	$(CPP) $(CPPFLAGS) $(SRC) -o $(BIN)

check: all
	./$(BIN)

clean:
	$(RM) $(BIN)

.PHONY: clean
