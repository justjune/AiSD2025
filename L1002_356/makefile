CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

L1002356.exe: L1002_356.o
  $(CXX) -o L102356.exe L1002_356.o

L1002_356.o: main.cpp
  $(CXX) $(CXXFLAGS) -c main.cpp

clean:
  rm -f L1002_356.o L1002356.exe
