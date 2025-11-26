CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

L103357.exe: L103_357.o
  $(CXX) -o L103357.exe L103_357.o

L103_357.o: main.cpp
  $(CXX) $(CXXFLAGS) -c main.cpp

clean:
  rm -f L103_357.o L103357.exe
