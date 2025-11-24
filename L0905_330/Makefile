objects=L0905_330.o L0905_330test.o

L0905_330.exe: $(objects)
	$(CXX) -o L0905_330.exe $(objects)
	
L0905_330.o: L0905_330.cpp L0905_330.hpp
	$(CXX) -c L0905_330.cpp

L0905_330test.o: L0905_330test.cpp
	$(CXX) -c L0905_330test.cpp

.PHONY: clean run
clean:
	$(RM) $(objects) L0905_330.exe

run:
	L0905_330.exe
all: L0905_330.exe run clean