CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = tree_program.exe
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	chcp 65001
	./$(TARGET)
	chcp 866

clean:
	del /Q *.o *.exe 2>nul || rm -f *.o $(TARGET)

.PHONY: all run clean
