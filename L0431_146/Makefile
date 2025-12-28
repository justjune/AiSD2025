CXX = g++

OBJ = L0431_146.o
EXE = L0431_146.exe

$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $(OBJ)

$(OBJ): L0431_146.cpp
	$(CXX) -c L0431_146.cpp -o $(OBJ)

.PHONY: clean run all

clean:
	rm -f $(OBJ) $(EXE)

run: $(EXE)
	./$(EXE)

all: $(EXE) run clean
