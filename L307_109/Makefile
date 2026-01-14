# Makefile для проекта поиска в BST
# ПМ-2025 Овсянникова Анастасия

CXX = g++
CXXFLAGS = -Wall -std=c++11 -I.

ifeq ($(OS),Windows_NT)
	RM = del /Q
	TARGET = tree_app.exe
else
	RM = rm -f
	TARGET = tree_app
endif

SRCS = L307_109test.cpp L307_109.cpp
OBJECTS = $(SRCS:.cpp=.o)

# Цель all ДОЛЖНА выполнять сборку программы
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Сборка $(TARGET) завершена"

$(OBJECTS): %.o: %.cpp L307_109.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)

.PHONY: all clean