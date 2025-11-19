CXX=g++

ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=
endif

10411_161.exe: 10411_161.o 10411_161test.o
	$(CXX) -o 10411_161.exe 10411_161.o 10411_161test.o

10411_161.o: 10411_161.hpp
	$(CXX) -c 10411_161.hpp

10411_161test.o: 10411_161test.cpp 10411_161.hpp
	$(CXX) -c 10411_161test.cpp

run:
	./10411_161.exe

.PHONY: clean 
clean:
	$(RM) *.o *.exe
