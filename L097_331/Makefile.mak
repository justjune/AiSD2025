CXX = g++

l970331o = L097_331.o L097_331test.o

L097_331.exe: $(l097331o)
  $(CXX) -o L097_331.exe $(l097331o)
  
L097_331.o: L097_331.cpp L097_331.hpp
  $(CXX) -c L097_331.cpp
  
L097_331test.o: L097_331test.cpp L097_331.hpp
  $(CXX) -c L097_331test.cpp
  
.PHONY: clean
clean:
  rm -f $(l097_331o) L097_331.exe