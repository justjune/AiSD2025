# Makefile for L025_077 - fast exponentiation
# PM-2025 Parfyonov Vyacheslav

CXX = g++

all: L025_077

L025_077: L025_077.o L025_077test.o
	$(CXX) -o L025_077.exe L025_077.o L025_077test.o
	@echo "=== L025_077 built successfully! ==="

run: L025_077
	./L025_077.exe

clean:
	rm -f L025_077.exe L025_077.o L025_077test.o
	@echo "=== Compiled files deleted ==="

help:
	@echo "=== Commands for L025_077 ==="
	@echo "make all    - build program"
	@echo "make run    - build and run"
	@echo "make clean  - delete compiled files"
	@echo "make help   - show this help"

.PHONY: all run clean help