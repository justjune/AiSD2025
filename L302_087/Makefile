ifeq ($(OS),Windows_NT)
	RM=rm
	EXT=.exe
else
	RM=rm
	EXT=

endif


l302087o=L302_087.o L302_087test.o
L302087.exe: $(l302087o)
	$(CXX) -o L302087.exe $(l302087o)

L302_087.o: L302_087.cpp
	$(CXX) -c L302_087.cpp

L302_087test.o: L302_087test.cpp L302_087.hpp
	$(CXX) -c L302_087test.cpp

.PHONY: clean
clean:
	$(RM) *.o *.exe
