objects=L1001_354.o L1001_354test.o

L1001_354.exe: $(objects)
	$(CXX) -o L1001_354.exe $(objects)
	
L1001_354.o: L1001_354.cpp L1001_354.hpp
	$(CXX) -c L1001_354.cpp

L1001_354test.o: L1001_354test.cpp
	$(CXX) -c L1001_354test.cpp

.PHONY: clean run
clean:
	$(RM) $(objects) L1001_354.exe

run:
	L1001_354.exe
all: L1001_354.exe run clean