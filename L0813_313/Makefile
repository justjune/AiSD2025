# МАКЕФАЙЛ ДЛЯ СБОРКИ ПРОЕКТА
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = L0813_313_program
SRCS = L0813_313_Test.cpp L0813_313.cpp
OBJS = $(SRCS:.cpp=.o)

# Цель по умолчанию
.DEFAULT_GOAL := all

# Основная цель - сборка программы
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Компиляция L0813_313_Test.cpp
L0813_313_Test.o: L0813_313_Test.cpp L0813_313.h
	$(CXX) $(CXXFLAGS) -c L0813_313_Test.cpp

# Компиляция L0813_313.cpp
L0813_313.o: L0813_313.cpp L0813_313.h
	$(CXX) $(CXXFLAGS) -c L0813_313.cpp

# Очистка собранных файлов (упрощенная версия)
clean:
	rm -f $(OBJS) $(TARGET) *.d

# Пересборка с нуля
rebuild: clean $(TARGET)

# Сборка и запуск с изменением кодовой страницы
run: $(TARGET)
ifeq ($(OS),Windows_NT)
	chcp 65001 > nul
	./$(TARGET)
	chcp 866 > nul
else
	./$(TARGET)
endif

# Полный цикл: сборка -> запуск -> очистка
all: $(TARGET) run clean

# Указываем что это цели, а не файлы
.PHONY: clean rebuild run all
