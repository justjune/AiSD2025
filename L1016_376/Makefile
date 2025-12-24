CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = subset_sum
SOURCES = main.cpp subset_sum.cpp
HEADERS = subset_sum.hpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run