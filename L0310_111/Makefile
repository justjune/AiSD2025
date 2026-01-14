CXX = g++
CXXFLAGS = -Wall -std=c++11 -I.
TARGET = bst_insert_app

SRCS = L0310_111.cpp L0310_111test.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = L0310_111.hpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean

