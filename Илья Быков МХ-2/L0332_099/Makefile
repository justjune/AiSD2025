# C++ compiler
CXX = g++

# Build L0332_099
L0332_099:
    $(CXX) -o L0332_099.exe L0332_099.cpp L0332_099test.cpp
    @echo "=== L0332_099 built successfully! ==="

# Run program
run: L0332_099
    ./L0332_099.exe

# Clean
clean:
    rm -f L0332_099.exe
    @echo "=== L0332_099.exe deleted ==="

# Help
help:
    @echo "=== Commands for L0332_099 ==="
    @echo "make L0332_099  - build program"
    @echo "make run       - build and run"
    @echo "make clean     - delete exe-file"
    @echo "make help      - show this help"

# Default target
all: L0332_099
