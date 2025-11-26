CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

L102356.exe: L102_356.o
  $(CXX) -o L102356.exe L102_356.o

L102_356.o: main.cpp
  $(CXX) $(CXXFLAGS) -c main.cpp

clean:
  rm -f L102_356.o L102356.exe
