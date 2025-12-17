CXX=g++
CXXFLAGS=-I"AiSD2025L0332_098"

ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif


l0333_099o=L0333_099.o L0333_099test.o

L0333_099.exe: $(l0333_099o)
	$(CXX) -o L0333_099.exe $(l0333_099o)

L0333_099.o: L0333_099.cpp
	$(CXX) $(CXXFLAGS) -c L0333_099.cpp

L0333_099test.o: L0333_099test.cpp L0333_099.hpp
	$(CXX) $(CXXFLAGS) -c L0333_099test.cpp

.PHONY: clean run all
clean:
	$(RM) -f $(l0333_099o) L0333_099.exe
run:
	L0333_099.exe
all: L0333_099.exe run clean
