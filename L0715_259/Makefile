CXX = g++
CXXFLAGS = -Wall -Wextra -g
TARGET = graph_test.exe

SOURCES = test.cpp graph.cpp
HEADERS = graph.hpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

test.o: test.cpp graph.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

graph.o: graph.cpp graph.hpp
	$(CXX) $(CXXFLAGS) -c graph.cpp

clean:
	del $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean rebuild run 