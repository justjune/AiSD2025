CXX=g++

ifeq ($(OS),Windows_NT)
	RM=del
	EXT=.exe
else
	RM=rm
	EXT=

endif

l0708_254o=L0708_254.o L0708_254test.o
L0708_254.exe: $(l0708_254o)
	$(CXX) -o L0708_254.exe $(l0708_254o)

L0708_254.o: L0708_254.cpp
	$(CXX) -c L0708_254.cpp

L0708_254test.o: L0708_254test.cpp L0708_254.hpp
	$(CXX) -c L0708_254test.cpp

.PHONY: clean
clean:
	$(RM) $(objects) $(l0708_254o) m.exe L0708_254.exe