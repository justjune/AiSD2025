CXX = g++

l714257o = L0714_257.o L0714_257test.o

L0714_257.exe: $(l714257o)
	$(CXX) -o L0714_257.exe $(l714257o)

L0714_257.o: L0714_257.cpp L0714_257.hpp
	$(CXX) -c L0714_257.cpp

L0714_257test.o: L0714_257test.cpp L0714_257.hpp
	$(CXX) -c L0714_257test.cpp

.PHONY: clean run all
clean:
	del $(l714257o) L0714_257.exe

run: L0714_257.exe
	@chcp 65001 & \
    	.\L0714_257.exe & \
    	chcp 866

all:
	$(MAKE) run
	$(MAKE) clean
