CXX = g++

o0810310 = L0810_301.o L0810_301_test.o

L0810_301.exe: $(o0810310)
	$(CXX) -o L0810_301.exe $(o0810310)
 
L0810_301.o: L0810_301.cpp L0810_301.hpp
	$(CXX) -c L0810_301.cpp

L0810_301_test.o: L0810_301_test.cpp L0810_301.hpp
	$(CXX) -c L0810_301_test.cpp

.PHONY: clean run all

clean:
	$(RM) $(o0810310) L0810_301.exe

run:
	L0810_301.exe

all: L0810_301.exe run clean
