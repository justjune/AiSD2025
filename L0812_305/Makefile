# МАКЕФАЙЛ ДЛЯ СБОРКИ ПРОЕКТА
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = graph_program
SRCS = graph.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -c graph.cpp

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean rebuild run

