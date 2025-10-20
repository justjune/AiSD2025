CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -std=c++17

# Имя исполняемого файла, будет L0334_099.
TARGET = L0334_099

$(TARGET): L0334_099.cpp
    $(CXX) $(CXXFLAGS) -o $@ $<

run: $(TARGET)
    ./$(TARGET)

clean:
    rm -f $(TARGET)

all: $(TARGET)

help:
    @echo "Доступные команды:"
    @echo "  make       - собрать проект"
    @echo "  make run   - собрать и запустить проект"
    @echo "  make clean - очистить проект"
