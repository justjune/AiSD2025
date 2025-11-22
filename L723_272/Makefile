CXX = g++

l723272o = L723_272.o L723_272test.o

L723_272.exe: $(l723272o)
	$(CXX) -o L723_272.exe $(l723272o)

L723_272.o: L723_272.cpp L723_272.hpp
	$(CXX) -c L723_272.cpp

L723_272test.o: L723_272test.cpp L723_272.hpp
	$(CXX) -c L723_272test.cpp

.PHONY: clean
clean:
	rm -f $(l723272o) L723_272.exe