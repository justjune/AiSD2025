CXX=g++

l031099o=L031_099.o L031_099test.o
L031099.exe: $(l031099o)
	$(CXX) -o L031099.exe $(l031099o)

L031_099.o: L031_099.cpp L031_099.hpp
	$(CXX) -c L031_099.cpp

L031_099test.o: L031_099test.cpp L031_099.hpp
	$(CXX) -c L031_099test.cpp

.PHONY: clean
clean:
	rm -f $(l031099o) L031099.exe