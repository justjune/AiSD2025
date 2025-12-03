# МАКЕФАЙЛ 
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = L0814_313_program
SRCS = L0814_313_Test.cpp L0814_313.cpp
OBJS = $(SRCS:.cpp=.o)

# Основная цель - сборка программы
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Компиляция L0814_313_Test.cpp
L0814_313_Test.o: L0814_313_Test.cpp L0814_313.h
	$(CXX) $(CXXFLAGS) -c L0814_313_Test.cpp

# Компиляция L0814_313.cpp
L0814_313.o: L0814_313.cpp L0814_313.h
	$(CXX) $(CXXFLAGS) -c L0814_313.cpp

# Очистка собранных файлов
clean:
ifeq ($(OS),Windows_NT)
		del $(TARGET) *.d
		del $(OBJECTS) *.d
else
		rm -f $(OBJS) $(TARGET) *.d
endif

# Пересборка с нуля
rebuild: clean $(TARGET)

# Сборка и запуск
run: $(TARGET)
	./$(TARGET)

# Указываем что это цели, а не файлы
.PHONY: clean rebuild run
