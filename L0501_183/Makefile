CXX=g++

ifeq ($(OS),Windows_NT)
	RM=del
	EXT=.exe
else
	RM=rm
	EXT=

endif

l0501183o=main.o test.o

L0501183.exe: $(l0501183o)
	$(CXX) -o L0501183.exe $(l0501183o)

main.o: main.cpp test.h
	$(CXX) -c main.cpp

test.o: test.cpp test.h binarySearch.h 
	$(CXX) -c test.cpp

run:
	./L0501183.exe

.PHONY: clean 
clean:
	$(RM) *.o *.exe