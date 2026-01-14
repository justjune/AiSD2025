CXX = g++

l309111o = L0309_111.o L0309_111test.o

L0309_111.exe: $(l309111o)
	$(CXX) -o L0309_111.exe $(l309111o)

L0309_111.o: L0309_111.cpp L0309_111.hpp
	$(CXX) -c L0309_111.cpp

L0309_111test.o: L0309_111test.cpp L0309_111.hpp
	$(CXX) -c L0309_111test.cpp

.PHONY: clean run all
clean:
	del $(l309111o) L0309_111.exe

run: L0309_111.exe
	@chcp 65001 & \
    	.\L0309_111.exe & \
    	chcp 866

all:
	$(MAKE) run
	$(MAKE) clean
