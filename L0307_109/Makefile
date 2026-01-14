CXX = g++
CXXFLAGS = -Wall -std=c++11 -I.
TARGET = tree_app
SRCS = L0307_109test.cpp L0307_109.cpp
OBJECTS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp L0307_109.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean