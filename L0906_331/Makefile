objects=L0906_331.o L0906_331test.o

L0906_331.exe: $(objects)
	$(CXX) -o L0906_331.exe $(objects)
	
L0906_331.o: L0906_331.cpp L0906_331.hpp
	$(CXX) -c L0906_331.cpp

L0906_331test.o: L0906_331test.cpp
	$(CXX) -c L0906_331test.cpp

.PHONY: clean run
clean:
	$(RM) $(objects) L0906_331.exe

run:
	L0906_331.exe
all: L0906_331.exe run clean