CXX = g++

# Переменные
OBJS = L0908_332.o L0908_332test.o
EXEC = L0908_332.exe
SRCS = L0908_332.cpp L0908_332test.cpp
HEADER = L0908_332.hpp

# Цели по умолчанию
all: $(EXEC) run clean

# Сборка исполняемого файла
$(EXEC): $(OBJS)
 $(CXX) -o $(EXEC) $(OBJS)

# Компиляция объектных файлов
L0908_332.o: L0908_332.cpp $(HEADER)
 $(CXX) -c L0908_332.cpp

L0908_332test.o: L0908_332test.cpp $(HEADER)
 $(CXX) -c L0908_332test.cpp

# Запуск программы
run: $(EXEC)
 ./$(EXEC)

# Очистка
clean:
 rm -f $(OBJS) $(EXEC)

# Фиктивные цели
.PHONY: all run clean