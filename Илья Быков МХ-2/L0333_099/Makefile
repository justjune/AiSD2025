# Определяем компилятор C++
CXX = g++

# Определяем флаги компиляции
CXXFLAGS = -Wall -std=c++17

# Определяем имя исполняемого файла
TARGET = L0333_099

$(TARGET): L0333_099.cpp
    $(CXX) $(CXXFLAGS) -o $@ $^

run: $(TARGET)
    ./$(TARGET)

clean:
    rm -f $(TARGET)
    @echo "Файл $(TARGET) удален."

all: $(TARGET)

# Правило 'help' для вывода справки.
help:
    @echo "Использование:"
    @echo "  make      - собрать проект"
    @echo "  make run  - собрать и запустить проект"
    @echo "  make clean- очистить проект"
