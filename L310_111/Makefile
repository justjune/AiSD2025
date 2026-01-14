# Makefile для проекта вставки в BST
# ПМ-2025 Овсянникова Анастасия

CXX = g++
CXXFLAGS = -Wall -std=c++11 -I.
TARGET = bst_insert_app

# Файлы проекта
SRCS = L310_111.cpp L310_111test.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = L310_111.hpp

ifeq ($(OS),Windows_NT)
    RM = del /Q
    TARGET := $(TARGET).exe
    RUN_CMD = $(TARGET)
else
    RM = rm -f
    RUN_CMD = ./$(TARGET)
endif

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Сборка завершена: $(TARGET)"

$(OBJS): %.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	@echo "=== Тестирование вставки в BST ==="
	$(RUN_CMD)

clean:
	$(RM) $(OBJS) $(TARGET)

