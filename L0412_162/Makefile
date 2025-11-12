ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif


l302087o=L0412_162.o L0412_162test.o
L302087.exe: $(l302087o)
	$(CXX) -o L302087.exe $(l302087o)

L0412_162.o: L0412_162.cpp
	$(CXX) -c L0412_162.cpp

L0412_162test.o: L0412_162test.cpp L0412_162.hpp
	$(CXX) -c L0412_162test.cpp

.PHONY: clean
clean:
	$(RM) *.o *.exe
