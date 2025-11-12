CXX=g++

ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif
l0413163o=main.o test.o

L0413163.exe: $(l0413163o)
	$(CXX) -o L0413163.exe $(l0413163o)

main.o: main.cpp test.h
	$(CXX) -c main.cpp

test.o: test.cpp test.h partition.h 
	$(CXX) -c test.cpp

run:
	./L0413163.exe

.PHONY: clean 
clean:
	$(RM) *.o *.exe