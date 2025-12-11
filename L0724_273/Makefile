CXX=g++

l0724273o=L0724_273.o L0724_273test.o
L0724273.exe: $(l0724273o)
	$(CXX) -o L0724273.exe $(l0724273o)

L0724_273.o: L0724_273.cpp L0724_273.hpp
	$(CXX) -c L0724_273.cpp

L0724_273test.o: L0724_273test.cpp L0724_273.hpp
	$(CXX) -c L0724_273test.cpp

.PHONY: clean run
clean:
	rm -f $(l0724273o) L0724273.exe

run: L0724273.exe
	./L0724273.exe
all: L0724_273.exe run clean
