CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = program
SOURCES = main.cpp
HEADERS = my_qsort.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	del $(TARGET).exe

.PHONY: clean
