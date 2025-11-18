CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

L102355.exe: L102_355.o
  $(CXX) -o L102355.exe L102_355.o

L102_355.o: L102_355.cpp
  $(CXX) $(CXXFLAGS) -c L102_355.cpp

clean:
  rm -f L102_355.o L102355.exe
