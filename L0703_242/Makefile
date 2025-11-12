CXX=g++

ifeq ($(OS),Windows_NT)
	RM=del
	EXT=.exe
else
	RM=rm
	EXT=

endif


l0703_242o=L0703_242.o L0703_242_test.o
L0703_242.exe: $(l0703_242o)
	$(CXX) -o L0703_242.exe $(l0703_242o)

L0703_242.o: L0703_242.cpp
	$(CXX) -c L0703_242.cpp

L0703_242_test.o: L0703_242_test.cpp L0703_242.hpp
	$(CXX) -c L0703_242_test.cpp

.PHONY: clean
clean:
	$(RM) $(objects) $(l0703_242o) m.exe L0703_242.exe