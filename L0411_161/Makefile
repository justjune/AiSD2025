ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif


l302087o=0411_161.o 0411_161test.o
L302087.exe: $(l302087o)
	$(CXX) -o L302087.exe $(l302087o)

0411_161.o: 0411_161.cpp
	$(CXX) -c 0411_161.cpp

0411_161test.o: 0411_161test.cpp 0411_161.hpp
	$(CXX) -c 0411_161test.cpp

.PHONY: clean
clean:
	$(RM) *.o *.exe
