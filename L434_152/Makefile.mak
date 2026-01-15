CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET := PriorityQueue
SRC    := main.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)