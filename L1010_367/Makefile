CXX = g++

l1010367o = L1010_367.o L1010_367test.o

L1010_367.exe: $(l1010367o)
	$(CXX) -o L1010_367.exe $(l1010367o)

L1010_367.o: L1010_367.cpp L1010_367.hpp
	$(CXX) -c L1010_367.cpp

L1010_367test.o: L1010_367test.cpp L1010_367.hpp
	$(CXX) -c L1010_367test.cpp

.PHONY: clean run all
clean:
	rm -f $(l1010367o) L1010_367.exe

run: L1010_367.exe
	@chcp 65001 & \
		./L1010_367.exe & \
		chcp 866

all: L1010_367.exe
	@{MAKE} run
	@{MAKE} clean
