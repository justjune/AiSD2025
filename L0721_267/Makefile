CXX=g++

l0311121o=main.o test.o

L0311121.exe: $(l0311121o)
	$(CXX) -o L0311121.exe $(l0311121o)

main.o: main.cpp test.h
	$(CXX) -c main.cpp

test.o: test.cpp test.h hash.h 
	$(CXX) -c test.cpp

run:
	./L0311121.exe

.PHONY: clean 
clean:
	$(RM) *.o *.exe