CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

L104357.exe: L104_357.o
  $(CXX) -o L104357.exe L104_357.o

L104_357.o: main.cpp
  $(CXX) $(CXXFLAGS) -c main.cpp

clean:
  rm -f L104_357.o L104357.exe
