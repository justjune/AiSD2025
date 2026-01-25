CXX=g++

l0804287o=L0804_287.o L0804_287_test.o

L0804_287.exe: $(l0804287o)
	$(CXX) -o L0804_287.exe $(l0804287o)
 
L0804_287.o: L0804_287.cpp
	$(CXX) -c L0804_287.cpp

L0804_287_test.o: L0804_287_test.cpp L0804_287.h
	$(CXX) -c L0804_287_test.cpp

.PHONY: clean run all

clean:
	$(RM) $(l0804287o) L0804_287.exe

run:
	L0804_287.exe

all: L0804_287.exe run clean
