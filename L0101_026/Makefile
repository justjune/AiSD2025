CXX = g++
CXXFLAGS = -std=c++11

l0101026o = L0101_026test.o
L0101026.exe: $(l0101026o)
	$(CXX) -o L0101026.exe $(l0101026o)

L0101_026test.o: L0101_026test.cpp L0101_026.hpp
	$(CXX) $(CXXFLAGS) -c L0101_026test.cpp

run: L0101026.exe
	./L0101026.exe

clean:
	del L0101_026test.o L0101026.exe 2>nul 2>nul

all: run clean

.PHONY: all run clean
	