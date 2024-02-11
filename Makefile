APPNAME = Tetris

# Directories
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

# Compilator

CXX = g++
CXXFLAGS = -I $(INCLUDE) -std=c++11 -stdlib=libc++ -L $(LIB) -framework Cocoa -framework OpenGL -framework IOKit
LIBS = -lglfw3

# Files

SRC_FILES = $(wildcard $(SRC)/*.c*)
SRC_OUTPUTS = $(patsubst $(SRC)/%.c%, $(OBJ)/%.o, $(SRC_FILES))


# Rules

all: $(BIN)/$(APPNAME)

$(BIN)/$(APPNAME) : $(SRC_OUTPUTS)
	$(CXX)  -o $@ $^ $(CXXFLAGS) $(LIBS)

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

run: 
	./$(BIN)/$(APPNAME)


clean:
	rm -f obj/*
	rm -f bin/*

.PHONY: clean all run



