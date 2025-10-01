# L023_069 - search string in text
# PM-2025 Parfyonov Vyacheslav

# C++ compiler
CXX = g++

# Build L023_069
L023_069:
	$(CXX) -o L023_069.exe L023_069.cpp L023_069test.cpp
	@echo "=== L023_069 built successfully! ==="

# Run program
run: L023_069
	./L023_069.exe

# Clean
clean:
	rm -f L023_069.exe
	@echo "=== L023_069.exe deleted ==="

# Help
help:
	@echo "=== Commands for L023_069 ==="
	@echo "make L023_069  - build program"
	@echo "make run       - build and run"
	@echo "make clean     - delete exe-file"
	@echo "make help      - show this help"

# Default target
all: L023_069