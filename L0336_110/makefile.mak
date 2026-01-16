CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = L0336_110.exe
SOURCES = L0336_110.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) 2>/dev/null || true

.PHONY: all run clean