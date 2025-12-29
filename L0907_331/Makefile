CXX = g++

# Переменные
OBJS = L0907_331.o L0907_331test.o
EXEC = L0907_331.exe
SRCS = L0907_331.cpp L0907_331test.cpp
HEADER = L0907_331.hpp

# Цели по умолчанию
all: $(EXEC) run clean

# Сборка исполняемого файла
$(EXEC): $(OBJS)
 $(CXX) -o $(EXEC) $(OBJS)

# Компиляция объектных файлов
L0907_331.o: L0907_331.cpp $(HEADER)
 $(CXX) -c L0907_331.cpp

L0907_331test.o: L0907_331test.cpp $(HEADER)
 $(CXX) -c L0907_331test.cpp

# Запуск программы
run: $(EXEC)
 ./$(EXEC)

# Очистка
clean:
 rm -f $(OBJS) $(EXEC)

# Фиктивные цели
.PHONY: all run clean