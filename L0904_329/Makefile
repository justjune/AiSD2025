objects=L0904_329.o L0904_329test.o

L0904_329.exe: $(objects)
	$(CXX) -o L0904_329.exe $(objects)
	
L0904_329.o: L0904_329.cpp L0904_329.hpp
	$(CXX) -c L0904_329.cpp

L0904_329test.o: L0904_329test.cpp
	$(CXX) -c L0904_329test.cpp

.PHONY: clean run
clean:
	$(RM) $(objects) L0904_329.exe

run:
	L0904_329.exe
all: L0904_329.exe run clean