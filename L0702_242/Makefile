ifeq ($(OS),Windows_NT)
	RM=del
	EXT=.exe
else
	RM=rm
	EXT=

endif


l07022412o=L0702_242.o L0702_242_test.o
L0702242.exe: $(l0702242o)
	$(CXX) -o L0702242.exe $(l0702242o)

L0702_242.o: L0702_242.cpp
	$(CXX) -c L0702_242.cpp

L0702_242_test.o: L0702_242_test.cpp L0702_242.hpp
	$(CXX) -c L0702_242_test.cpp

.PHONY: clean
clean:
	$(RM) $(objects) $(l0702242o) m.exe L0702242.exe