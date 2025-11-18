CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

L10102356.exe: L10102_356.o
  $(CXX) -o L10102356.exe L10102_356.o

L10102_356.o: L10102_356.cpp
  $(CXX) $(CXXFLAGS) -c L10102_356.cpp

clean:
  rm -f L10102_356.o L10102356.exe
