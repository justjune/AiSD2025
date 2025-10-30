CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = program.exe
SOURCES = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	chcp 65001
	./$(TARGET)
	chcp 866

clean:
	rm -f *.o $(TARGET)

.PHONY: all run clean
