CXX = g++

# Флаги компиляции для поиска заголовочных файлов в родительском каталоге
CXXFLAGS = -I../L0907_331

# Переменные
OBJS = L0908_332.o L0908_332test.o
EXEC = L0908_332.exe
SRCS = L0908_332.cpp L0908_332test.cpp
HEADER = L0908_332.hpp

# Цели по умолчанию
all: $(EXEC) run clean

# Сборка исполняемого файла
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Компиляция объектных файлов
L0908_332.o: L0908_332.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c L0908_332.cpp

L0908_332test.o: L0908_332test.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c L0908_332test.cpp

# Запуск программы из родительского каталога
run: $(EXEC)
	cd .. && ./L0908_332/$(EXEC)

# Очистка
clean:
	rm -f $(OBJS) $(EXEC)

# Фиктивные цели
.PHONY: all run clean