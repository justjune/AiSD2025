CXX=g++

ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=
endif

10412_162.exe: 10412_162.o 10412_162test.o
	$(CXX) -o 10412_162.exe 10412_162.o 10412_162test.o

10412_162.o: 10412_162.hpp
	$(CXX) -c 10412_162.hpp

10412_162test.o: 10412_162test.cpp 10412_162.hpp
	$(CXX) -c 10412_162test.cpp

run:
	./10412_162.exe

.PHONY: clean 
clean:
	$(RM) *.o *.exe
