CXX=g++

ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif


l0332_098o=L0332_098.o L0332_098test.o

L0332_098.exe: $(l0332_098o)
	$(CXX) -o L0332_098.exe $(l0332_098o)

L0332_098.o: L0332_098.cpp
	$(CXX) -c L0332_098.cpp

L0332_098test.o: L0332_098test.cpp L0332_098.hpp
	$(CXX) -c L0332_098test.cpp

.PHONY: clean run all
clean:
	$(RM) -f $(l0332_098o) L0332_098.exe
run:
	L0332_098.exe
all: L0332_098.exe run clean
