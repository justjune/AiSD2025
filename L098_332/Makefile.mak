CXX = g++

l098332o = L098_332.o L098_332test.o

L098_332.exe: $(l098332o)
  $(CXX) -o L098_332.exe $(l098332o)

L098_332.o: L098_332.cpp L098_332.hpp
  $(CXX) -c L098_332.cpp

L098_332test.o: L098_332test.cpp L098_332.hpp
  $(CXX) -c L098_332test.cpp

.PHONY: clean
clean:
  rm -f $(l098332o) L098_332.exe