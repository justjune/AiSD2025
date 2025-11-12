CXX=g++

l713256o=src/L713_256.o tests/L713_256test.o

L713256.exe: $(l713256o)
    $(CXX) -o L713256.exe $(l713256o)

src/L713_256.o: src/L713_256.cpp include/L713_256.hpp
    $(CXX) -c src/L713_256.cpp -Iinclude

tests/L713_256test.o: tests/L713_256test.cpp include/L713_256.hpp
    $(CXX) -c tests/L713_256test.cpp -Iinclude

.PHONY: clean
clean:
    rm -f $(l713256o) L713256.exe

