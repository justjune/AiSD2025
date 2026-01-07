CXX=g++

l409154o=L0409_154.o L0409_154test.o
L0409_154.exe: $(l409154o)
	$(CXX) -o L0409_154.exe $(l409154o)

L0409_154.o: L0409_154.cpp L0409_154.hpp
	$(CXX) -c L0409_154.cpp

L0409_154test.o: L0409_154test.cpp L0409_154.hpp
	$(CXX) -c L0409_154test.cpp

.PHONY: clean run all
clean:
	rm -f $(l409154o) L0409_154.exe
run: L0409_154.exe
	./L0409_154.exe
all: run clean
