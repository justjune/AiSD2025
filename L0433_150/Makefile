CXX = g++

SRC = L0143_150_Test.cpp
OBJ = L0433_150_Test.o
EXE = L0433_150_Test.exe

$(EXE): $(OBJ)
  $(CXX) -o $(EXE) $(OBJ)

$(OBJ): $(SRC) L0433_150.hpp
  $(CXX) -c $(SRC) -o $(OBJ)

.PHONY: clean run all

clean:
  rm -f $(OBJ) $(EXE)

run: $(EXE)
  ./$(EXE)

all: $(EXE) run clean
