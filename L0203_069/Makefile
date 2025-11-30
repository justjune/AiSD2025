CXX = g++

l023069o = L023_069.o L023_069test.o

L023_069.exe: $(l023069o)
	$(CXX) -o L023_069.exe $(l023069o)

L023_069.o: L023_069.cpp L023_069.hpp
	$(CXX) -c L023_069.cpp

L023_069test.o: L023_069test.cpp L023_069.hpp
	$(CXX) -c L023_069test.cpp

.PHONY: clean
clean:
	rm -f $(l023069o) L023_069.exe