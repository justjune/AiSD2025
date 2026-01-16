CXX = g++

SRC = L0431_146_Test.cpp
OBJ = L0431_146_Test.o
EXE = L0431_146_Test.exe

$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $(OBJ)

$(OBJ): $(SRC) L0431_146.hpp
	$(CXX) -c $(SRC) -o $(OBJ)

.PHONY: clean run all

clean:
	rm -f $(OBJ) $(EXE)

run: $(EXE)
	./$(EXE)

all: $(EXE) run clean
