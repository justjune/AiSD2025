CXX = g++

l724273o = L724_273.o L724_273test.o

L724_273.exe: $(l724273o)
	$(CXX) -o L724_273.exe $(l724273o)

L724_273.o: L724_273.cpp L724_273.hpp
	$(CXX) -c L724_273.cpp

L724_273test.o: L724_273test.cpp L724_273.hpp
	$(CXX) -c L724_273test.cpp

.PHONY: clean
clean:
	rm -f $(l724273o) L724_273.exe