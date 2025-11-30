CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++17 -DUNICODE -D_UNICODE
LDFLAGS = -municode

TARGET = L0715_259.exe
SOURCES = L0715_259test.cpp L0715_259.cpp
HEADERS = L0715_259.hpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

L0715_259test.o: L0715_259test.cpp L0715_259.hpp
	$(CXX) $(CXXFLAGS) -c L0715_259test.cpp

L0715_259.o: L0715_259.cpp L0715_259.hpp
	$(CXX) $(CXXFLAGS) -c L0715_259.cpp

clean:
ifeq ($(OS),Windows_NT)
	del $(TARGET)
	del $(OBJECTS)
else
	rm -f $(TARGET)
	rm -f $(OBJECTS)
endif

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run 