# МАКЕФАЙЛ ДЛЯ СБОРКИ ПРОЕКТА
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = L0812_305_program
SRCS = L0812_305.cpp
OBJS = $(SRCS:.cpp=.o)

# Цель по умолчанию
.DEFAULT_GOAL := all

# Основная цель - сборка
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

L0812_305.o: L0812_305.cpp L0812_305.h
	$(CXX) $(CXXFLAGS) -c L0812_305.cpp

# Очистка (упрощенная версия)
clean:
	rm -f $(OBJS) $(TARGET) *.d

# Пересборка
rebuild: clean $(TARGET)

# Запуск с изменением кодовой страницы на Unicode
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

.PHONY: clean rebuild run all
