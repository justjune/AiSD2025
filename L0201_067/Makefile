CXX = g++
CXXFLAGS = -std=c++11


L0201067.exe: L0201_067test.o
	$(CXX) -o L0201067.exe L0201_067test.o

L0201_067test.o: L0201_067test.cpp L0201_067.hpp
	$(CXX) $(CXXFLAGS) -c L0201_067test.cpp

run: L0201067.exe
	./L0201067.exe

clean:
	del L0201_067test.o L0201067.exe 2>nul 2>nul

all: run clean

.PHONY: all run clean