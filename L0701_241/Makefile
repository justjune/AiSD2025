CXX=g++

ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif


l0701_241o= L0701_241_test.o
L0701_241.exe: $(l0701_241o)
	$(CXX) -o L0701_241.exe $(l0701_241o)

L0701_241_test.o: L0701_241_test.cpp L0701_241.hpp
	$(CXX) -c L0701_241_test.cpp

.PHONY: clean run all
clean:
	$(RM) -f $(l0701_241o) L0701_241.exe
run:
	L0701_241.exe
all: L0701_241.exe run clean