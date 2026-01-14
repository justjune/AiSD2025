CXX = g++

OBJ = L0433_150.o
EXE = L0433_150.exe

$(EXE): $(OBJ)
  $(CXX) -o $(EXE) $(OBJ)

$(OBJ): L0433_150.cpp
  $(CXX) -c L0433_150.cpp -o $(OBJ)

.PHONY: clean run all

clean:
  rm -f $(OBJ) $(EXE)

run: $(EXE)
  ./$(EXE)

all: $(EXE) run clean
