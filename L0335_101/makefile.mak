CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = L0335_101.exe
SOURCES = L0335_101.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	chcp 65001
	./$(TARGET)
	chcp 866

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean