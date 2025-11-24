objects=L0903_329.o L0903_329test.o

L0903_329.exe: $(objects)
	$(CXX) -o L0903_329.exe $(objects)
	
L0903_329.o: L0903_329.cpp L0903_329.hpp
	$(CXX) -c L0903_329.cpp

L0903_329test.o: L0903_329test.cpp
	$(CXX) -c L0903_329test.cpp

.PHONY: clean run
clean:
	$(RM) $(objects) L0903_329.exe

run:
	L0903_329.exe
all: L0903_329.exe run clean