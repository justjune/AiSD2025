ifeq ($(OS),Windows_NT)
	RM = del /Q
	EXT = .exe
else
	RM = rm -f
	EXT =
endif

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = L431146$(EXT)
OBJ = L431_146.o

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

L431_146.o: L431_146.cpp
	$(CXX) $(CXXFLAGS) -c L431_146.cpp

.PHONY: clean
clean:
	$(RM) $(OBJ) $(TARGET)
