ifeq ($(OS),Windows_NT)
	RM=del
	EXT=.exe
else
	RM=rm
	EXT=

endif


l07032412o=L0703_242.o L0703_242_test.o
L0703242.exe: $(l0703242o)
	$(CXX) -o L0703242.exe $(l0703242o)

L0703_242.o: L0703_242.cpp
	$(CXX) -c L0703_242.cpp

L0703_242_test.o: L0703_242_test.cpp L0703_242.hpp
	$(CXX) -c L0703_242_test.cpp

.PHONY: clean
clean:
	$(RM) $(objects) $(l0703242o) m.exe L0703242.exe