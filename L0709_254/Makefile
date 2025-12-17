CXX=g++

ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif

l0709_254o=L0709_254.o L0709_254test.o
L0709_254.exe: $(l0709_254o)
	$(CXX) -o L0709_254.exe $(l0709_254o)

L0709_254.o: L0709_254.cpp
	$(CXX) -c L0709_254.cpp

L0709_254test.o: L0709_254test.cpp L0709_254.hpp
	$(CXX) -c L0709_254test.cpp

.PHONY: clean run all
clean:
	$(RM) -f $(l0709_254o) L0709_254.exe
run:
	L0709_254.exe
all: L0709_254.exe run clean