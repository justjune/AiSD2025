CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

L1004357.exe: L1004_357.o
  $(CXX) -o L1004357.exe L1004_357.o

L1004_357.o: main.cpp
  $(CXX) $(CXXFLAGS) -c main.cpp

clean:
  rm -f L1004_357.o L1004357.exe
