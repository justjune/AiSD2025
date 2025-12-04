CXX = g++
CXXFLAGS = -I"."

ifeq ($(OS),Windows_NT)
	RM = del /Q
	EXT = .exe
else
	RM = rm -f
	EXT =
endif

TARGET = L0705_244$(EXT)

OBJ = main.o L0705_244.o

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

main.o: test_L0705_244.cpp L0705_244.hpp
	$(CXX) $(CXXFLAGS) -c test_L0705_244.cpp

L0705_244.o: L0705_244.cpp L0705_244.hpp
	$(CXX) $(CXXFLAGS) -c L0705_244.cpp

.PHONY: clean run all
clean:
	$(RM) $(OBJ) $(TARGET)

run:
	./$(TARGET)

all: $(TARGET)
