CXX=g++
CXXFLAGS=-I"AiSD2025L0332_098"

ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif


l0334_099o=L0334_099.o L0334_099test.o

L0334_099.exe: $(l0334_099o)
	$(CXX) -o L0334_099.exe $(l0334_099o)

L0334_099.o: L0334_099.cpp
	$(CXX) $(CXXFLAGS) -c L0334_099.cpp

L0334_099test.o: L0334_099test.cpp L0334_099.hpp
	$(CXX) $(CXXFLAGS) -c L0334_099test.cpp

.PHONY: clean run all
clean:
	$(RM) -f $(l0334_099o) L0334_099.exe
run:
	L0334_099.exe
all: L0334_099.exe run clean
