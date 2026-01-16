CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic

l0411161_o = L0411_161.o L0411_161test.o

L0411_161.exe: $(l0411161_o)
	$(CXX) $(CXXFLAGS) -o L0411_161.exe $(l0411161_o)

L0411_161.o: L0411_161.cpp L0411_161.hpp
	$(CXX) $(CXXFLAGS) -c L0411_161.cpp

L0411_161test.o: L0411_161test.cpp L0411_161.hpp
	$(CXX) $(CXXFLAGS) -c L0411_161test.cpp

.PHONY: clean run all

clean:
	rm -f $(l0411161_o) L0411_161.exe

run: L0411_161.exe
	./L0411_161.exe

all: clean L0411_161.exe
