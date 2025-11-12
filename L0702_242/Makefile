CXX=g++

ifeq ($(OS),Windows_NT)
	RM=del
	EXT=.exe
else
	RM=rm
	EXT=

endif


l0702_242o=L0702_242.o L0702_242_test.o
L0702_242.exe: $(l0702_242o)
	$(CXX) -o L0702_242.exe $(l0702_242o)

L0702_242.o: L0702_242.cpp
	$(CXX) -c L0702_242.cpp

L0702_242_test.o: L0702_242_test.cpp L0702_242.hpp
	$(CXX) -c L0702_242_test.cpp

.PHONY: clean
clean:
	$(RM) $(objects) $(l0702_242o) m.exe L0702_242.exe