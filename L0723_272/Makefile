CXX=g++

l0723272o=L0723_272.o L0723_272test.o
L0723272.exe: $(l0723272o)
	$(CXX) -o L0723272.exe $(l0723272o)

L0723_272.o: L0723_272.cpp L0723_272.hpp
	$(CXX) -c L0723_272.cpp

L0723_272test.o: L0723_272test.cpp L0723_272.hpp
	$(CXX) -c L0723_272test.cpp

.PHONY: clean run all
clean:
	rm -f $(l0723272o) L0723272.exe

run: L0723272.exe
	./L0723272.exe
all: L0723_272.exe run clean