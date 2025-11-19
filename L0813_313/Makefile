# МАКЕФАЙЛ 
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = flow_program
SRCS = main.cpp flow_graph.cpp
OBJS = $(SRCS:.cpp=.o)

# Основная цель - сборка программы
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Компиляция main.cpp
main.o: main.cpp flow_graph.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Компиляция flow_graph.cpp
flow_graph.o: flow_graph.cpp flow_graph.h
	$(CXX) $(CXXFLAGS) -c flow_graph.cpp

# Очистка собранных файлов
clean:
	rm -f $(OBJS) $(TARGET)

# Пересборка с нуля
rebuild: clean $(TARGET)

# Сборка и запуск
run: $(TARGET)
	./$(TARGET)

# Указываем что это цели, а не файлы
.PHONY: clean rebuild run
