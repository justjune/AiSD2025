
l302087o=L302_087.o L302_087test.o
L302087.exe: $(l302087o)
	$(CXX) -o L302087$(EXT) $(l302087o)

L302_087.o: L302_087.cpp
	$(CXX) -c L302_087.cpp

L302_087test.o: L302_087test.cpp L302_087.hpp
	$(CXX) -c L302_087test.cpp

.PHONY: clean run all
clean:
	RM *.o  *.exe
run:
	chcp 65001
	L302087.exe
	chcp 866
all: L302087.exe run clean
