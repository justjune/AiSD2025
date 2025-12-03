# МАКЕФАЙЛ ДЛЯ СБОРКИ ПРОЕКТА
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = L0812_305_program
SRCS = L0812_305.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

L0812_305.o: L0812_305.cpp L0812_305.h
	$(CXX) $(CXXFLAGS) -c L0812_305.cpp

clean:
ifeq ($(OS),Windows_NT)
		del $(TARGET) *.d
		del $(OBJECTS) *.d
else
		rm -f $(OBJS) $(TARGET) *.d
endif

rebuild: clean $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean rebuild run

