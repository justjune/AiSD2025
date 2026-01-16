CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic

l0412162_o = L0412_162.o L0412_162test.o

L0412_162.exe: $(l0412162_o)
	$(CXX) $(CXXFLAGS) -o L0412_162.exe $(l0412162_o)

L0412_162.o: L0412_162.cpp L0412_162.hpp
	$(CXX) $(CXXFLAGS) -c L0412_162.cpp

L0412_162test.o: L0412_162test.cpp L0412_162.hpp
	$(CXX) $(CXXFLAGS) -c L0412_162test.cpp

.PHONY: clean run all

clean:
	rm -f $(l0412162_o) L0412_162.exe

run: L0412_162.exe
	./L0412_162.exe

all: clean L0412_162.exe
