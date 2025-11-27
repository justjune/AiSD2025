CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

L1003357.exe: L1003_357.o
  $(CXX) -o L1003357.exe L1003_357.o

L1003_357.o: main.cpp
  $(CXX) $(CXXFLAGS) -c main.cpp

clean:
  rm -f L1003_357.o L1003357.exe
